# Inner Workings

## 1.0 - Functions (in C++)

Functions are binds to C++ code. For example, the "println" function.

```c++

int b_println(std::string arguments) {
    std::cout << PrettyPrint(arguments) << std::endl;
    return 1;
}

```

## 1.1 - Eval

Eval works like a loop, it evaluates a statement and returns the evaluation of the statement.

Statements return strings, and the strings are turned into integers, floats, etc ...

Variables have evaluated statements, so 

```

var c = 1 + 1

print(c)

```

Is the same as 

```

print(1 + 1)

```

## 1.2 Formatting print

You can use printf for formatting print.

`printf(1 + 1, " is the result of 1 + 1");`

## 1.3 Nesting

nested functions in functions are usually used like

function( (myfunc(params)) , other stuff )

It gets the return code from "myfunc" and uses it as a parameter.