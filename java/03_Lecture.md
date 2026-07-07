# Lecture 3: Variables & Data Types in Java

---

# 1. What is a Variable?

A **variable** is a named memory location used to store data.

Example:

```java
int age = 22;
```

* `int` → data type
* `age` → variable name (identifier)
* `22` → value

Think of a variable as a labeled box.

```
age
┌─────┐
│ 22  │
└─────┘
```

---

# 2. What is an Identifier?

An **identifier** is simply the **name** you give to variables, methods, classes, etc.

Example:

```java
int studentAge;
double salary;
String firstName;
```

### Good identifier names

```java
studentAge
totalMarks
employeeSalary
```

### Bad names

```java
a
x
temp1
```

Keep names **simple, meaningful, and descriptive**.

---

# 3. Declaring Variables

### Syntax

```java
datatype variableName;
```

Example

```java
int age;
```

### Declaration + Initialization

```java
int age = 22;
```

---

# 4. Java is Statically Typed

Java is a **statically typed language**.

That means:

* Every variable must have a datatype.
* The datatype is checked at compile time.
* Once declared, the variable can only store that type.

Example

```java
int age = 20;

age = 25;      // Correct

age = "John";  // Error
```

The compiler catches the error before the program runs.

---

# 5. Data Types

Java data types are divided into two categories.

```
Data Types
│
├── Primitive
│
└── Non-Primitive (Reference Types)
```

---

## Primitive Data Types

Primitive types store actual values.

### Integer Types

| Type  | Size    |
| ----- | ------- |
| byte  | 8 bits  |
| short | 16 bits |
| int   | 32 bits |
| long  | 64 bits |

---

### Decimal Types

| Type   | Size    |
| ------ | ------- |
| float  | 32 bits |
| double | 64 bits |

---

### Character

| Type | Size              |
| ---- | ----------------- |
| char | 16 bits (Unicode) |

---

### Boolean

```java
boolean
```

Stores only

```text
true
false
```

---

# 6. What are Bits and Bytes?

A **bit** is the smallest unit of data.

It can store only

```
0
or
1
```

A **byte** consists of **8 bits**.

```
1 Byte = 8 Bits
```

Example

```
10110110

↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑

8 bits = 1 byte
```

---

# 7. Why do we say 8-bit, 16-bit, 32-bit?

Suppose a datatype has **n bits**.

Each bit has **2 choices**

```
0
1
```

Therefore,

```
Total combinations = 2ⁿ
```

Example

```
8 bits

2 × 2 × 2 × 2 × 2 × 2 × 2 × 2

= 2⁸

= 256 combinations
```

---

# 8. Are All Numbers Signed in Java?

Yes.

Except for **char**, all integer types in Java are **signed**.

That means they can store

```
Negative numbers

Zero

Positive numbers
```

Java does **not** provide unsigned integer types like C/C++.

---

# 9. Why isn't the maximum value 2ⁿ − 1?

A common confusion is:

> "If there are 2⁸ = 256 combinations, shouldn't the maximum value be 255?"

That would only be true if **all bits were used for positive numbers**.

But Java stores **both positive and negative numbers**.

One bit is effectively used as the **sign** (implemented using two's complement, explained below).

So the values are split between negative and positive numbers.

---

# 10. Range Formula

For a signed datatype with **n bits**

```
Minimum = -2⁽ⁿ⁻¹⁾

Maximum = 2⁽ⁿ⁻¹⁾ - 1
```

Example

### byte (8 bits)

```
Minimum

= -2⁷

= -128
```

```
Maximum

= 2⁷ - 1

= 127
```

Hence,

```
byte

-128 to 127
```

---

# 11. Primitive Data Type Ranges

| Type    | Size          | Range                 |
| ------- | ------------- | --------------------- |
| byte    | 8 bits        | -128 to 127           |
| short   | 16 bits       | -32,768 to 32,767     |
| int     | 32 bits       | -2³¹ to 2³¹−1         |
| long    | 64 bits       | -2⁶³ to 2⁶³−1         |
| float   | 32 bits       | Approx. ±3.4 × 10³⁸   |
| double  | 64 bits       | Approx. ±1.8 × 10³⁰⁸  |
| char    | 16 bits       | 0 to 65,535 (Unicode) |
| boolean | JVM dependent | true / false          |

---

# 12. How are Negative Numbers Stored?

Computers store everything in **binary**.

Positive numbers are straightforward:

```
5

00000101
```

Negative numbers are **not** stored with a simple minus sign.

Java uses a method called **Two's Complement**.

### Steps to store -5

Start with +5

```
00000101
```

Invert all bits

```
11111010
```

Add 1

```
11111011
```

So,

```
-5

=

11111011
```

This is called **Two's Complement Representation**.

It is used because it makes arithmetic (addition, subtraction, etc.) much simpler for the CPU.

---

## Key Takeaways

* A **variable** stores data.
* An **identifier** is the variable's name.
* Java is **statically typed**, so every variable must have a declared datatype.
* Primitive data types include integers, decimals, characters, and booleans.
* **1 byte = 8 bits**.
* With **n bits**, there are **2ⁿ possible binary combinations**.
* Java integer types (except `char`) are **signed**, with range:

  * Minimum = **−2⁽ⁿ⁻¹⁾**
  * Maximum = **2⁽ⁿ⁻¹⁾ − 1**
* Negative numbers are stored using **Two's Complement** representation.
