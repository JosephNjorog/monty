[Brainf*ck script to multiply two digits (res<10)]

1: store ascii digit
> ,
2: store ascii digit
> ,

# 0: 10
<<++++++++++

# ascii to int
# Loop (10)
[-
>-----
>-----
<<
]
>++
>++

# LOOP for (1:) times
<[-

# increment (0:) by (2:) and store (2:) in (3:)
>[->+<
<<+
>>
]

# return (3:) to (2:)
>[-
<+>
]

# back to (1:)
<<
]

# int to str
<
++++++++++
++++++++++
++++++++++
++++++++++
++++++++
.
