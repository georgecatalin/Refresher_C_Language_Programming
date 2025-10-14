/* 
    examples of using the null statement:

    while((*text++=getchar()) != '\n')
    ;

    etc


1. As an empty loop body:
```
while (getchar() != '\n')
    ; // null statement: do nothing, just loop
```

2. In an if statement with no action:
```
if (x > 0)
    ; // null statement: do nothing if x > 0
else
    printf("x is not positive\n");
```

3. For loop with no body:
```c
for (i = 0; i < 10; i++)
    ; // null statement: just increment i
```

4. As a placeholder in switch cases:
```
switch (ch) {
    case 'a':
        ; // null statement: intentionally do nothing
        break;
    default:
        printf("Not 'a'\n");
}
```

5. After a label with no statement:
```
start:
    ; // null statement after label
printf("Started\n");
```

*/