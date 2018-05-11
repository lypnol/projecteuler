#!/usr/bin/env python3
# -*- coding: utf-8 -*-


TEMPLATES = {
    'cpp': """#include <iostream>

using namespace std;

int solve() {
    // solution code

}

int main() {
    cout << solve() << "\\n";
    return 0;
}
""",
    'go': """package main

import "fmt"

func solve() int {
    // solution code
    
}

func main() {
    fmt.Println(solve())
}
""",
    'py': """
def solve():
    # solution code


print(solve())
""",
    'js': """
function solve() {
    // solution code

}

console.log(solve());
"""

}
