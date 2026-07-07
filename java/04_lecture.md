# Lecture 4: How Java Stores Negative Numbers & Floating-Point Numbers

---

# Part 1: How Java Stores Negative Numbers

We already know:

```text
byte = 8 bits
Range = -128 to +127
```

The question is:

> **How does Java actually store a negative number like -42 in binary?**

Java uses **Two's Complement Representation**.

---

# Step 1: Store +42 in Binary

Convert 42 into binary.

```text
42 ÷ 2 = 21 remainder 0
21 ÷ 2 = 10 remainder 1
10 ÷ 2 = 5  remainder 0
5  ÷ 2 = 2  remainder 1
2  ÷ 2 = 1  remainder 0
1  ÷ 2 = 0  remainder 1
```

Reading from bottom:

```text
101010
```

Since byte has 8 bits:

```text
00101010
```

Memory:

```text
128 64 32 16 8 4 2 1

0   0  1  0 1 0 1 0

= 32 + 8 + 2

= 42
```

---

# Step 2: First Complement (1's Complement)

Invert every bit.

```text
00101010

↓

11010101
```

Every

```text
0 → 1

1 → 0
```

---

# Step 3: Second Complement (2's Complement)

Add 1.

```text
11010101
+
00000001
----------
11010110
```

So Java stores

```java
byte b = -42;
```

as

```text
11010110
```

---

# Why Two's Complement?

It allows the CPU to perform **addition and subtraction using the same hardware**, making arithmetic much faster and simpler.

---

# MSB and LSB

Every binary number has:

## MSB

**Most Significant Bit**

It is the **leftmost bit**.

Example

```text
11010110

↑

MSB
```

---

## LSB

**Least Significant Bit**

It is the **rightmost bit**.

```text
11010110
       ↑

      LSB
```

---

# Why is the MSB Important?

For signed integers in Java:

```text
MSB = 0

Positive number
```

Example

```text
00101010

= +42
```

---

```text
MSB = 1

Negative number
```

Example

```text
11010110

= -42
```

The remaining bits store the value using **Two's Complement**.

---

# How to Convert Back to Decimal

Suppose memory contains

```text
11010110
```

MSB is 1.

Therefore,

```text
Negative number
```

Now:

### Step 1

Invert

```text
11010110

↓

00101001
```

### Step 2

Add 1

```text
00101001
+
00000001
----------
00101010
```

This equals

```text
42
```

Hence

```text
11010110

=

-42
```


# Part 2: How Java Stores Floating-Point Numbers

Until now, we've learned how computers store **integers**.

Example:

```text
42
```

becomes

```text
00101010
```

using binary.

But what about numbers like

```text
3.14
8.125
0.7
```

These have a decimal point.

How can a computer store those?

---

# Step 1: Decimal Numbers Can Also Be Written in Binary

We already know how to convert the **integer part** into binary.

Example

```text
13

↓

1101₂
```

But now suppose we have

```text
13.625
```

The integer part is easy.

```text
13

↓

1101₂
```

Now we only need to convert

```text
0.625
```

---

# Step 2: How Do We Convert Fractions to Binary?

For integers, we **divide by 2 repeatedly**.

For fractions, we do the opposite.

We **multiply by 2 repeatedly**.

### Example: Convert 0.625 to binary

```
0.625 × 2 = 1.25
```

Write down the integer part.

```
1
```

Keep the decimal part.

```
0.25
```

Again,

```
0.25 × 2 = 0.5
```

Write

```
0
```

Continue.

```
0.5 × 2 = 1.0
```

Write

```
1
```

Now nothing remains.

Reading from top to bottom,

```text
101
```

Therefore,

```text
0.625₁₀

=

0.101₂
```

---

# Example: 8.125

Split into two parts.

```
8

and

0.125
```

Integer part

```
8

↓

1000₂
```

Now convert

```
0.125
```

```
0.125 × 2 = 0.25 → 0

0.25 × 2 = 0.5 → 0

0.5 × 2 = 1 → 1
```

So,

```text
0.125

=

0.001₂
```

Therefore,

```text
8.125

=

1000.001₂
```

This binary representation **ends after three fractional bits**.

Nothing repeats.

That is extremely important.

---

# What is a Floating-Point Number?

Numbers with decimal points are called **floating-point numbers**.

The decimal point is said to "float" because it can appear anywhere.

For example,

```
3.14

0.00052

527.8

100000.25
```

all have decimal points in different positions.

---

# Java Has Two Floating-Point Types

| Type   | Memory  |
| ------ | ------- |
| float  | 32 bits |
| double | 64 bits |

---

# Why Do We Write `f`?

When Java sees

```java
0.7
```

it automatically assumes

```java
double
```

because Java treats decimal literals as `double` by default.

Therefore,

```java
float x = 0.7;
```

produces an error.

You must tell Java

> "Store this number as a float."

by writing

```java
float x = 0.7f;
```

The `f` simply means

```
This decimal number is a float.
```

---

# What Does "Single Precision" Mean?

This term confuses almost everyone because "precision" isn't usually defined.

**Precision** simply means:

> **How accurately a number can be stored.**

Think of memory like a notebook.

Suppose you are allowed to write only **7 digits**.

```
3.1415926535
```

becomes

```
3.141593
```

You lost some information.

Now suppose someone gives you a notebook with space for **16 digits**.

Now you can write

```
3.141592653589793
```

Much more accurate.

This is exactly what happens inside the computer.

---

### Float (Single Precision)

A float has **32 bits**.

Those 32 bits can store roughly **7 decimal digits accurately**.

Example

```
123.456789123
```

may become

```
123.45679
```

because there isn't enough space.

---

### Double (Double Precision)

A double has **64 bits**.

It can store roughly **15–16 decimal digits accurately**.

So,

```
123.456789123456789
```

is stored much more accurately.

That is why it is called **double precision**.

It has roughly **twice the precision** of a float.

Notice:

* **Single precision ≠ one decimal place**
* **Double precision ≠ two decimal places**

It refers to **how many significant digits can be represented accurately**.

---

# Why Does 8.125 Print Correctly?

```java
float f = 8.125f;

System.out.printf("%.20f%n", f);
```

Output

```
8.12500000000000000000
```

Why?

Because

```
8.125

=

1000.001₂
```

This binary number **ends**.

Since it ends, Java can store it **exactly**.

No approximation is needed.

---

# Why Does 0.7 Print Weirdly?

```java
float f = 0.7f;

System.out.printf("%.20f%n", f);
```

Output

```
0.69999998807907100000
```

Java did **not** change the number.

The problem happened **earlier**, when Java stored it in memory.

Remember,

```
0.7

=

0.10110011001100110011...
```

This never ends.

Java had to cut it off because a float has only **32 bits**.

So the stored value becomes approximately

```
0.699999988079071...
```

That is the actual value sitting in memory.

---

# Then Why Does `println()` Show 0.7?

```java
System.out.println(f);
```

prints

```
0.7
```

because `println()` displays a **rounded, user-friendly** version of the number.

It hides the tiny error.

---

# What Does `printf("%.20f", f)` Actually Do?

`printf()` does **not** change the number.

It only changes **how the number is displayed**.

Let's understand the format string.

```
%.20f
```

means:

* `%` → start of formatting.
* `.20` → show **20 digits after the decimal point**.
* `f` → print as a floating-point number.

So

```java
System.out.printf("%.20f", f);
```

means:

> "Print whatever value is stored in memory, showing 20 digits after the decimal point."

It doesn't create the error—it simply **reveals** the approximation that was already stored.

---

# Memory vs Display

The most important takeaway is this:

**Memory stores one value. Display can show it in different ways.**

```
Memory
↓

0.699999988079071...
```

`println()`

↓

```
0.7
```

`printf("%.20f")`

↓

```
0.69999998807907100000
```

Both are printing the **same value**. `printf` is simply showing you more of the stored approximation.

---

I think this version builds the concepts in the right order:

1. How binary fractions work.
2. Why some fractions terminate and others repeat.
3. Why computers approximate.
4. What precision actually means.
5. Why `float` and `double` differ.
6. Why `0.7f` behaves differently from `8.125f`.
7. What `printf` is really doing.

Each idea naturally explains the next one, so you don't have to memorize isolated facts.
