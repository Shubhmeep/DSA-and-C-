
# Lecture 5: Type Conversion (Type Casting) in Java

## What is Type Conversion?

Type conversion is the process of converting a value from one datatype to another.

Example:

```java
int x = 20;
double y = x;
```

Here, the integer `20` is converted into the double value `20.0`.

There are two types of type conversion:

```text
Type Conversion
│
├── Implicit (Automatic / Widening)
│
└── Explicit (Manual / Narrowing / Casting)
```

---

# 1. Implicit Conversion (Widening Conversion)

Implicit conversion happens automatically when the destination datatype is larger than the source datatype.

Example:

```java
byte b = 24;
int i = b;

System.out.println(i);
```

Output:

```text
24
```

No casting is required.

---

## Why does this work?

A `byte` occupies **8 bits**, whereas an `int` occupies **32 bits**.

Suppose `24` is stored as a byte.

```text
00011000
```

When converting to an `int`, Java simply extends it to 32 bits.

```text
00000000 00000000 00000000 00011000
```

No information is lost, so the value remains `24`.

---

## Rule for Implicit Conversion

The destination datatype must be **wider** than the source datatype.

Example:

```text
byte → short → int → long → float → double
```

Since every datatype on the right can store all values of the datatype before it, Java performs the conversion automatically.

---

## Why is it called Widening?

Think of pouring water from a small glass into a large bucket.

```text
Small Glass
      ↓
Large Bucket
```

Nothing is lost.

Similarly,

```text
byte (8 bits)
      ↓
int (32 bits)
```

The value fits completely, so no data is lost.

---

# 2. Explicit Conversion (Casting / Narrowing Conversion)

Explicit conversion is required when converting a larger datatype into a smaller datatype.

Example:

```java
int i = 100;
byte b = (byte)i;
```

Here, `(byte)` is called a **cast**.

You are telling Java:

> "I know data might be lost. Convert it anyway."

---

## Why doesn't Java do this automatically?

Consider:

```java
int i = 300;
byte b = i;
```

This produces a compile-time error because a `byte` can store only:

```text
-128 to 127
```

Since `300` is outside this range, Java prevents the conversion.

To force it, you must explicitly cast:

```java
byte b = (byte)i;
```

---

## Why is it called Narrowing?

Think of pouring water from a large bucket into a small glass.

```text
Large Bucket
      ↓
Small Glass
```

Some water may spill.

Similarly,

```text
int (32 bits)
      ↓
byte (8 bits)
```

Some information may be lost.

---

# What Actually Happens During Narrowing?

Consider:

```java
int i = 300;
byte b = (byte)i;
```

Many students think Java somehow converts `300` into `44`.

That is **not** what happens.

Java simply copies only the number of bits that the destination datatype can hold.

---

## Step 1: Store 300 as an int

300 in binary is:

```text
100101100
```

Stored in a 32-bit integer:

```text
00000000 00000000 00000001 00101100
```

---

## Step 2: Convert to byte

A byte has space for only **8 bits**.

Java keeps only the **last 8 bits**.

```text
00000000 00000000 00000001 00101100
                             ↓
                         00101100
```

The first 24 bits are discarded.

This process is called **truncation**.

---

## Step 3: Interpret the Remaining Bits

The remaining bits are

```text
00101100
```

Convert them back to decimal.

```text
32 + 8 + 4 = 44
```

Therefore,

```java
System.out.println(b);
```

prints

```text
44
```

---

# Is Java Performing Modulo?

Notice:

```text
300 % 256 = 44
```

This is true because a byte has

```text
8 bits

↓

2⁸ = 256 possible bit patterns
```

When Java discards the higher bits, the result becomes mathematically equivalent to taking the value modulo `256`.

However,

> **Java is NOT actually performing `% 256`.**

It simply **keeps the lowest 8 bits**.

The modulo result is just a consequence of how binary numbers work.

---

# Another Example

```java
int x = 260;
byte b = (byte)x;

System.out.println(b);
```

Binary:

```text
00000000 00000000 00000001 00000100
```

Keep only the last 8 bits.

```text
00000100
```

Output:

```text
4
```

Again,

```text
260 % 256 = 4
```

---

# What if the Remaining Bits Start with 1?

Suppose after truncation the remaining bits are

```text
11111100
```

The leftmost bit (MSB) is `1`.

That means Java interprets the number as **negative** using **Two's Complement**.

Therefore, narrowing conversions can sometimes produce negative values.

---

# Important Terms

### Widening Conversion

* Small datatype → Large datatype
* Automatic
* Safe
* No information is lost

Example:

```text
byte → int
```

---

### Narrowing Conversion

* Large datatype → Small datatype
* Manual
* Requires explicit casting
* Data may be lost

Example:

```text
int → byte
```

---

### Truncating Conversion

During narrowing conversion, Java **discards the higher-order bits** and keeps only the bits that fit in the destination datatype.

Example:

```text
32-bit int

↓

Keep last 8 bits

↓

byte
```

This process is called **truncation**.

---

# Lecture 5(B): Type Promotion in Java

## First, What is Type Promotion?

Type promotion is the **automatic conversion of operands to a larger datatype before performing an operation**.

Think of it as:

> **Before Java performs a calculation, it may first promote the variables to a larger datatype.**

This happens **only in expressions** like:

```java
a + b
a * b
a - b
a / b
```

It does **not** happen in simple assignments.

---

# Why Does Java Promote Types?

Suppose we have:

```java
byte a = 100;
byte b = 27;
```

A byte can only store

```text
-128 to 127
```

Now add them.

```text
100 + 27 = 127
```

Still okay.

But what if:

```java
byte a = 120;
byte b = 20;
```

Then

```text
120 + 20 = 140
```

140 cannot fit inside a byte.

Instead of checking overflow every time, Java simply says:

> **Whenever arithmetic is performed on small integer types, first convert them to `int`.**

This makes arithmetic simpler and faster.

---

# Rule 1: All Small Integer Types Become `int`

The following datatypes are promoted to `int` before arithmetic:

* `byte`
* `short`
* `char`

Even if both operands are bytes.

Example:

```java
byte a = 10;
byte b = 20;

System.out.println(a + b);
```

What happens?

```text
byte

↓

int

+

byte

↓

int
```

Java actually performs

```java
int + int
```

The result is

```text
30
```

whose datatype is

```text
int
```

---

# Example 2

```java
byte a = 10;
byte b = 20;

byte c = a + b;
```

Compile-time error.

Why?

Because

```java
a + b
```

becomes

```java
int + int
```

The result is an `int`.

So Java sees

```java
byte c = int;
```

which is not allowed.

Correct code:

```java
int c = a + b;
```

or

```java
byte c = (byte)(a + b);
```

---

# Rule 2: If One Operand Is Larger, Promote to That Type

Suppose:

```java
int a = 10;
long b = 20;
```

Java promotes the smaller datatype.

```text
int

↓

long
```

The operation becomes

```java
long + long
```

Result datatype:

```text
long
```

---

Another example

```java
float a = 10;
double b = 5;
```

Java promotes

```text
float

↓

double
```

Operation becomes

```java
double + double
```

Result datatype:

```text
double
```

---

# General Promotion Order

Java promotes operands according to this order:

```text
byte
   ↓
short
   ↓
char
   ↓
int
   ↓
long
   ↓
float
   ↓
double
```

The final result has the **widest datatype** involved in the expression.

---

# Examples

### Example 1

```java
byte a = 10;
short b = 20;
```

Promotion:

```text
byte

↓

int

+

short

↓

int
```

Result:

```text
int
```

---

### Example 2

```java
int a = 10;
long b = 20;
```

Promotion:

```text
int

↓

long
```

Result:

```text
long
```

---

### Example 3

```java
long a = 10;
float b = 20;
```

Promotion:

```text
long

↓

float
```

Result:

```text
float
```

---

### Example 4

```java
float a = 5;
double b = 2;
```

Promotion:

```text
float

↓

double
```

Result:

```text
double
```

---

# Why Isn't `byte + byte` a `byte`?

This confuses many beginners.

Consider:

```java
byte a = 100;
byte b = 100;
```

Result

```text
200
```

cannot fit in a byte.

Instead of checking overflow every time,

Java simply promotes both operands to `int`.

So

```java
byte + byte
```

actually becomes

```java
int + int
```

---

# Does Promotion Change the Original Variable?

No.

Example

```java
byte a = 10;
byte b = 20;

int c = a + b;
```

After execution:

```text
a

↓

still byte
```

```text
b

↓

still byte
```

Only the temporary values used during the calculation become `int`.

The original variables never change their datatype.

---

# Type Promotion vs Type Conversion

| Type Conversion                           | Type Promotion                       |
| ----------------------------------------- | ------------------------------------ |
| Assignment                                | Arithmetic expression                |
| Converts one variable to another datatype | Converts operands before calculation |
| May be implicit or explicit               | Always automatic                     |
| Example: `int → double`                   | Example: `byte + byte → int`         |

---

# Memory View

Suppose

```java
byte a = 10;
byte b = 20;
```

Memory

```text
a

00001010
```

```text
b

00010100
```

Before addition Java temporarily creates

```text
00000000 00000000 00000000 00001010
```

and

```text
00000000 00000000 00000000 00010100
```

Then performs

```text
int + int
```

The result is

```text
30
```

stored as an `int`.

The original bytes remain unchanged.

---

# Key Takeaways

* Type promotion happens **during arithmetic expressions**, not assignments.
* `byte`, `short`, and `char` are **always promoted to `int`** before arithmetic.
* If operands have different types, Java promotes the smaller type to the larger one.
* The result of an expression has the **widest datatype** involved.
* Type promotion is temporary; it does **not** change the original variable's datatype.

---

# Interview Questions (Easy → Hard)

1. What is type promotion in Java?

2. What is the difference between type promotion and type casting?

3. Why does `byte + byte` produce an `int`?

4. Predict the output:

```java
byte a = 10;
byte b = 20;

System.out.println(a + b);
```

5. Why does this code fail?

```java
byte a = 10;
byte b = 20;
byte c = a + b;
```

6. Predict the datatype of the result:

```java
short + char
```

7. Predict the datatype of the result:

```java
int + long
```

8. Predict the datatype of the result:

```java
long + float
```

9. Predict the datatype of the result:

```java
float + double
```

10. Explain step by step what happens in memory when Java evaluates:

```java
byte a = 10;
byte b = 20;

int c = a + b;
```

Include:

* Why the operands become `int`
* Why the original variables remain `byte`
* Why the result is `int` instead of `byte`
