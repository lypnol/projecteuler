#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# stdlib
import subprocess
import stat
import sys
import os
import os.path
# project
from tools.utils import tool_for_lang

class CompilationError(Exception): pass
class CodeRuntimeError(Exception): pass
class GoDependenciesError(Exception): pass

BUILDS_PATH = "builds"
if not os.path.exists(BUILDS_PATH):
    os.mkdir(BUILDS_PATH)

class Runner:
    def __init__(self, language, filepath):
        self.language = language
        self.filepath = filepath
        self.args = []
        build = os.path.join(BUILDS_PATH, os.path.basename(filepath).split(".")[0])
        if language == "cpp":
            compile_output = subprocess.check_output(
                ["g++", "-Wall", "-O3", "-std=c++11", "-o", build, filepath]
                ).decode()
            if compile_output:
	            raise CompilationError(compile_output)
            self.executable = build
        elif language == "go":
            dep_output = subprocess.check_output(
                ["go", "get", "-d", os.path.join(".", filepath)]
                ).decode()
            if dep_output:
	            raise GoDependenciesError(dep_output)
            compile_output = subprocess.check_output(
                ["go", "build", "-o", build, filepath]
                ).decode()
            if compile_output:
	            raise CompilationError(compile_output)
            os.chmod(build, os.stat(build).st_mode | stat.S_IEXEC)
            self.executable = build
        else:
            self.executable = tool_for_lang(language)
            self.args = [filepath]

    def run(self):
        try:
            p = subprocess.Popen(
                [self.executable]+self.args,
                stdin=sys.stdin,
                stdout=sys.stdout,
                stderr=sys.stderr,
                close_fds=True)
            p.wait()
        except OSError as e:
            if e.errno == os.errno.ENOENT:
            	# executable not found
            	return CompilationError(e)
            # subprocess exited with another error
            return CodeRuntimeError(e)
