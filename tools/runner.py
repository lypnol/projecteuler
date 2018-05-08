#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# stdlib
import subprocess
import stat
import os
import tempfile
# project
from tools.utils import tool_for_lang

class CompilationError(Exception): pass
class CodeRuntimeError(Exception): pass
class GoDependenciesError(Exception): pass

class Runner:
    def __init__(self, language, filepath):
        self.language = language
        self.filepath = filepath
        self.args = []
        if language == "cpp":
            tmp = tempfile.NamedTemporaryFile(prefix="aoc")
            tmp.close()
            compile_output = subprocess.check_output(
                ["g++", "-Wall", "-O3", "-std=c++11", "-o", tmp.name, filepath]
                ).decode()
            if compile_output:
	            raise CompilationError(compile_output)
            self.executable = tmp.name
        elif language == "go":
            dep_output = subprocess.check_output(
                ["go", "get", "-d", os.path.join(".", filepath)]
                ).decode()
            if dep_output:
	            raise GoDependenciesError(dep_output)
            tmp = tempfile.NamedTemporaryFile(prefix="aoc")
            tmp.close()
            compile_output = subprocess.check_output(
                ["go", "build", "-o", tmp.name, filepath]
                ).decode()
            if compile_output:
	            raise CompilationError(compile_output)
            os.chmod(tmp.name, os.stat(tmp.name).st_mode | stat.S_IEXEC)
            self.executable = tmp.name
        else:
            self.executable = tool_for_lang(language)
            self.args = [filepath]

    def run(self):
        try:
            return subprocess.check_output([self.executable]+self.args).decode().rstrip()
        except OSError as e:
            if e.errno == os.errno.ENOENT:
            	# executable not found
            	return CompilationError(e)
            # subprocess exited with another error
            return CodeRuntimeError(e)
