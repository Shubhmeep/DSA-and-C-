# Lecture 6: Bitwise Operators

Think of **bitwise operators** as tools that work directly on the **binary bits** of numbers.

Java stores integers in binary: `0`s and `1`s.

Example:

```java
int a = 5;  // binary: 0101
int b = 3;  // binary: 0011
```

Now bitwise operators compare or move those bits.

**1. AND `&`**

`&` gives `1` only when both bits are `1`.

```text
  0101   5
& 0011   3
------
  0001   1
```

```java
System.out.println(5 & 3); // 1
```

Think: “both must be ON.”

**2. OR `|`**

`|` gives `1` if at least one bit is `1`.

```text
  0101   5
| 0011   3
------
  0111   7
```

```java
System.out.println(5 | 3); // 7
```

Think: “at least one is ON.”

**3. XOR `^`**

`^` gives `1` only when the bits are different.

```text
  0101   5
^ 0011   3
------
  0110   6
```

To master XOR, treat it as a difference detector.

```
0 ^ 0 = 0
1 ^ 1 = 0
0 ^ 1 = 1
1 ^ 0 = 1
```
So the rule is:
Same bits cancel to 0. (A number XORed with itself disappears)
Different bits become 1.

**Core XOR Laws**
You need these to become fluent:
```
x ^ x = 0
x ^ 0 = x
x ^ y = y ^ x
(x ^ y) ^ z = x ^ (y ^ z)
```

To master XOR, treat it as a **difference detector**.

```text
0 ^ 0 = 0
1 ^ 1 = 0
0 ^ 1 = 1
1 ^ 0 = 1
```

So the rule is:

```text
Same bits cancel to 0.
Different bits become 1.
```

## Core XOR Laws

You need these to become fluent:

```java
x ^ x = 0
x ^ 0 = x
x ^ y = y ^ x
(x ^ y) ^ z = x ^ (y ^ z)
```

The most important idea:

```text
A number XORed with itself disappears.
```

Example:

```java
int ans = 5 ^ 7 ^ 5;
```

Rearrange mentally:

```text
5 ^ 5 ^ 7 = 0 ^ 7 = 7
```

So:

```java
ans = 7
```

This is why XOR is powerful in DSA.

---

## Visual Example

```text
5 = 0101
3 = 0011

5 ^ 3:

  0101
^ 0011
------
  0110 = 6
```

Bits that were different became `1`.

---

## Pattern 1: Find Single Number

Problem: Every number appears twice except one.

```java
int[] nums = {4, 1, 2, 1, 2};
```

Use XOR:

```java
int ans = 0;

for (int num : nums) {
    ans ^= num;
}

System.out.println(ans); // 4
```

Why?

```text
0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2

1 cancels 1
2 cancels 2

left: 4
```

This is the most famous XOR pattern.

---

## Pattern 2: Find Missing Number

Problem: You have numbers from `0` to `n`, but one is missing.

```java
int[] nums = {0, 1, 3};
```

The missing number is `2`.

Code:

```java
int missingNumber(int[] nums) {
    int xor = 0;

    for (int i = 0; i <= nums.length; i++) {
        xor ^= i;
    }

    for (int num : nums) {
        xor ^= num;
    }

    return xor;
}
```

Why it works:

```text
All numbers from 0 to n
XOR all numbers actually present

Same numbers cancel.
Missing number remains.
```

---

## Pattern 3: Swap Two Numbers Using XOR

This is mostly for understanding, not recommended in real code.

```java
int a = 5;
int b = 9;

a = a ^ b;
b = a ^ b;
a = a ^ b;

System.out.println(a); // 9
System.out.println(b); // 5
```

Why?

```text
a = a ^ b
b = (a ^ b) ^ b = a
a = (a ^ b) ^ a = b
```

Again: same values cancel.

---

## Pattern 4: Check If Two Numbers Are Different At a Bit

Suppose:

```java
int a = 5; // 0101
int b = 3; // 0011
```

```java
int diff = a ^ b; // 0110
```

Wherever `diff` has `1`, `a` and `b` had different bits.

This is useful in advanced problems.

---

## Pattern 5: Find Two Single Numbers

Problem: Every number appears twice except two numbers.

```java
int[] nums = {1, 2, 1, 3, 2, 5};
```

Answer:

```text
3 and 5
```

Step 1: XOR everything.

```java
int xor = 0;
for (int num : nums) {
    xor ^= num;
}
```

Now:

```text
xor = 3 ^ 5
```

Step 2: Find a bit where those two numbers differ.

```java
int mask = xor & -xor;
```

Step 3: Split numbers into two groups.

```java
int a = 0;
int b = 0;

for (int num : nums) {
    if ((num & mask) == 0) {
        a ^= num;
    } else {
        b ^= num;
    }
}
```

Full code:

```java
int[] singleNumber(int[] nums) {
    int xor = 0;

    for (int num : nums) {
        xor ^= num;
    }

    int mask = xor & -xor;

    int a = 0;
    int b = 0;

    for (int num : nums) {
        if ((num & mask) == 0) {
            a ^= num;
        } else {
            b ^= num;
        }
    }

    return new int[]{a, b};
}
```

This is a FAANG-level XOR pattern.

---

## How To Think In Interviews

When you see:

```text
Every element appears twice except one
```

Immediately think:

```text
XOR
```

When you see:

```text
Find missing number from range 0 to n
```

Think:

```text
XOR or math sum
```

When you see:

```text
Every element appears twice except two elements
```

Think:

```text
XOR + split by differing bit
```

When you see:

```text
Need to compare bits
```

Think:

```text
XOR tells which bits are different
```


**4. NOT `~`**

`~` flips every bit.

```text
5  =  00000101
~5 =  11111010
```

In Java:

```java
System.out.println(~5); // -6
```

Why `-6`? Because Java uses a system called **two’s complement** for negative numbers. For now, remember this simple rule:

```java
~x == -(x + 1)
```

So:

```java
~5 == -6
~0 == -1
~10 == -11
```

**5. Left Shift `<<`**

`<<` moves bits to the left.

```text
5      = 0101
5 << 1 = 1010
```

That becomes `10`.

```java
System.out.println(5 << 1); // 10
```

Each left shift usually means “multiply by 2.”

```java
5 << 1  // 10
5 << 2  // 20
5 << 3  // 40
```

Think: move left, number gets bigger.

In Java, a `byte` has **8 bits**:

```text
128  64  32  16   8   4   2   1
 0    0   0   0   1   0   0   0   = 8
```

So:

```java
byte b = 8;
```

Binary:

```text
00001000
```

## What `b << 1` Means

Left shift by 1 means:

```text
Move every bit one step left.
Put 0 on the right.
```

So:

```text
00001000  = 8
<< 1
00010000  = 16
```

Again:

```text
00010000  = 16
<< 1
00100000  = 32
```

Again:

```text
00100000  = 32
<< 1
01000000  = 64
```

Again:

```text
01000000  = 64
<< 1
10000000
```

Now this is important.

For a Java `byte`, `10000000` means:

```text
-128
```

Not positive `128`.

Why? Because Java `byte` is signed. Its range is:

```text
-128 to 127
```

The leftmost bit is the **sign bit**.

```text
0xxxxxxx = positive
1xxxxxxx = negative
```

So:

```text
10000000 = -128
```

Then shift again:

```text
10000000
<< 1
00000000
```

The `1` falls off the left side, and `0` comes in from the right.

Result:

```text
0
```

So the sequence is:

```text
8 -> 16 -> 32 -> 64 -> -128 -> 0
```

## But Java Has One Catch

This does **not** compile:

```java
byte b = 8;
b = b << 1; // error
```

Because Java promotes `byte` to `int` before shifting.

You need a cast:

```java
byte b = 8;

b = (byte)(b << 1);
System.out.println(b); // 16
```

Or use compound assignment:

```java
byte b = 8;

b <<= 1;
System.out.println(b); // 16
```

`b <<= 1` automatically casts back to `byte`.

## Full Example

```java
public class Main {
    public static void main(String[] args) {
        byte b = 8;

        System.out.println(b); // 8

        b <<= 1;
        System.out.println(b); // 16

        b <<= 1;
        System.out.println(b); // 32

        b <<= 1;
        System.out.println(b); // 64

        b <<= 1;
        System.out.println(b); // -128

        b <<= 1;
        System.out.println(b); // 0
    }
}
```

Output:

```text
8
16
32
64
-128
0
```

Key mental model:

```text
Left shift moves bits left.
For normal positive ints: multiply by 2.
For byte/overflow: bits can fall off, and sign bit can turn the number negative.
```

**IMPORTANT**
Yes, exactly: **the MSB can change**, but the key point is **where the shifting actually happens**.

In Java, shift operators do **not** operate directly on `byte` or `short`.

They operate only on:

```java
int
long
```

So when you write:

```java
byte b = 8;
b = (byte)(b << 1);
```

Java first converts `b` to `int`.

```text
byte b = 8

as byte:
00001000

promoted to int:
00000000 00000000 00000000 00001000
```

Then shifting happens on the **32-bit int**, not the 8-bit byte:

```text
00000000 00000000 00000000 00001000
<< 1
00000000 00000000 00000000 00010000
```

That is `16`.

Then you cast back to byte:

```java
(byte) 16
```

So it becomes:

```text
00010000
```

Still `16`.

## Why Not Shift Directly On Byte?

Because Java’s arithmetic rules promote smaller integer types to `int`.

These types:

```java
byte
short
char
```

are promoted to:

```java
int
```

before arithmetic and bitwise operations.

Examples:

```java
byte a = 5;
byte b = 6;

byte c = a + b; // error
```

Why error?

Because:

```java
a + b
```

becomes:

```java
int + int
```

So result is `int`.

Same idea:

```java
byte b = 8;
byte c = b << 1; // error
```

Because:

```java
b << 1
```

produces an `int`.

You need:

```java
byte c = (byte)(b << 1);
```

## But What About `b <<= 1`?

This works:

```java
byte b = 8;
b <<= 1;
```

Because compound assignment includes an implicit cast.

This:

```java
b <<= 1;
```

is roughly like:

```java
b = (byte)(b << 1);
```

So shifting still happens as an `int`, then Java squeezes the result back into 8 bits.

## Now About MSB

You asked the right question:

> definition wise MSB is changing right?

Yes, but there are two different MSBs to think about.

### 1. MSB During the Actual Shift

Actual shift happens on `int`, so the MSB is bit `31`.

```text
int has 32 bits:

bit 31                          bit 0
  ↓                              ↓
00000000 00000000 00000000 00001000
```

When shifting `8 << 1`, nothing interesting happens to the `int` MSB.

```text
00000000 00000000 00000000 00001000
<< 1
00000000 00000000 00000000 00010000
```

Still positive.

### 2. MSB After Casting Back To Byte

When you cast back to `byte`, Java keeps only the lowest 8 bits.

So if the result is:

```text
00000000 00000000 00000000 10000000
```

Casting to byte keeps:

```text
10000000
```

For byte, that leftmost bit is the sign bit.

```text
10000000 = -128
```

So yes, the byte’s MSB changes, but **after the int operation is narrowed back to byte**.

## Visual Example

```java
byte b = 64;
b <<= 1;
System.out.println(b);
```

Step by step:

As byte:

```text
01000000 = 64
```

Promote to int:

```text
00000000 00000000 00000000 01000000
```

Shift as int:

```text
00000000 00000000 00000000 10000000
```

That int value is:

```text
128
```

Cast back to byte:

```text
10000000
```

But byte range is:

```text
-128 to 127
```

So:

```text
10000000 = -128
```

Final output:

```text
-128
```

## Another Example

```java
byte b = -128;
b <<= 1;
System.out.println(b);
```

As byte:

```text
10000000 = -128
```

When promoted to int, Java sign-extends it:

```text
11111111 11111111 11111111 10000000
```

Shift left:

```text
11111111 11111111 11111111 00000000
```

That int is:

```text
-256
```

Cast back to byte keeps only lower 8 bits:

```text
00000000
```

Final result:

```text
0
```

So:

```java
byte b = -128;
b <<= 1;
System.out.println(b); // 0
```

## The Big Rule

Definition-wise:

```text
Shifts are defined on int and long.
byte, short, and char are promoted to int first.
```

Memory-wise:

```text
byte still stores only 8 bits.
short still stores only 16 bits.
```

Behavior-wise:

```text
After cast/compound assignment, Java truncates back to 8 or 16 bits.
```

So the clean mental model is:

```text
byte b = 64;
b <<= 1;

1. b becomes int
2. int shifts
3. result is cast back to byte
4. byte MSB may become sign bit
```

That is why you see:

```text
8 -> 16 -> 32 -> 64 -> -128 -> 0
```

**For int shifting, Java takes the shift amount modulo 32**

No problem. Forget “mod” for a second. Think of it like a **clock**.

An `int` has **32 bit positions**:

```text
0, 1, 2, 3, ..., 30, 31
```

There is no position `32`.

So Java wraps around.

Like a clock:

```text
After 12 comes 1 again.
```

For `int`:

```text
After 31 comes 0 again.
```

So:

```text
shift by 0   means position 0
shift by 1   means position 1
shift by 2   means position 2
...
shift by 31  means position 31
shift by 32  wraps to position 0
shift by 33  wraps to position 1
shift by 34  wraps to position 2
```

That is all “mod 32” means.

## Example With `1 << k`

Start:

```java
1
```

Binary:

```text
00000000 00000000 00000000 00000001
```

Now:

```java
1 << 0
```

means keep the `1` at position `0`.

```text
00000000 00000000 00000000 00000001 = 1
```

```java
1 << 1
```

move it to position `1`.

```text
00000000 00000000 00000000 00000010 = 2
```

```java
1 << 2
```

move it to position `2`.

```text
00000000 00000000 00000000 00000100 = 4
```

Now jump:

```java
1 << 31
```

move it to position `31`, the last possible position.

```text
10000000 00000000 00000000 00000000
```

This is the sign bit, so Java prints:

```text
-2147483648
```

Now the confusing one:

```java
1 << 32
```

You may expect the `1` to fall off.

But Java says:

```text
For int, shift number wraps every 32.
```

So:

```java
1 << 32
```

is treated like:

```java
1 << 0
```

Result:

```text
1
```

And:

```java
1 << 33
```

is treated like:

```java
1 << 1
```

Result:

```text
2
```

## Tiny Table

```text
Expression     Java treats as     Result

1 << 0         1 << 0             1
1 << 1         1 << 1             2
1 << 2         1 << 2             4
1 << 31        1 << 31            -2147483648
1 << 32        1 << 0             1
1 << 33        1 << 1             2
1 << 34        1 << 2             4
```

## Why?

Because Java only looks at the last 5 bits of the shift amount for `int`.

But you do **not** need to deeply understand that yet.

For now memorize:

```text
int has 32 bits.
So shift amount loops every 32.
```

Like:

```text
0, 1, 2, ..., 31, 0, 1, 2, ...
```

So:

```java
1 << 32
```

does **not** mean shift 32 times.

In Java it means:

```java
1 << 0
```

because the shift count wraps around.


**6. Right Shift `>>`**

`>>` moves bits to the right.

```text
8      = 1000
8 >> 1 = 0100
```

That becomes `4`.

```java
System.out.println(8 >> 1); // 4
```

Each right shift usually means “divide by 2.”

```java
8 >> 1  // 4
8 >> 2  // 2
8 >> 3  // 1
```

Think: move right, number gets smaller.

**Quick Visual Summary**

```text
a = 5  -> 0101
b = 3  -> 0011

a & b  -> 0001 -> 1
a | b  -> 0111 -> 7
a ^ b  -> 0110 -> 6
```

The main idea:

```text
&  = both bits are 1
|  = at least one bit is 1
^  = bits are different
~  = flip all bits
<< = shift left, multiply by 2
>> = shift right, divide by 2
```

For DSA, the most important ones are usually `&`, `|`, `^`, `<<`, and `>>`.