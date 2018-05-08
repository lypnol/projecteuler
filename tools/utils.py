#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# stdlib
from shutil import which


def is_tool(name):
    return which(name) is not None

def tool_for_lang(lang):
    if lang == 'cpp':
        return 'g++'
    elif lang == 'go':
        return 'go'
    elif lang == 'js':
        return 'node'
    elif lang == 'py':
        return 'python3'
    return lang
