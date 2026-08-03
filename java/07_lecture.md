# Bit Manipulation continued...


1. Youtube Video watched: https://www.youtube.com/watch?v=T56nhL8Y1po 

## Certain Patterns in Bit Manipulation

Pattern Index:

```text
1. Convert decimal to binary using while loop
2. Check whether the i-th bit is set or not
3. Make the i-th bit a set bit
4. Check the i-th bit using right shift
5. Unset the i-th bit
6. Check odd or even using the last bit
7. Remove the rightmost set bit
8. Swap two numbers using XOR
9. Count number of bit flips to convert a to b
10. Find the rightmost set bit mask
```

### 1. Convert Decimal to Binary Using a While Loop

To convert a decimal number into binary, repeatedly divide the number by `2` and store the remainder.

The remainder tells us the current binary bit:

```text
number % 2 = last binary bit
number / 2 = remove the last processed bit
```

Since the remainders come from right to left, we add each new bit to the front of the answer string.

```java
static String decimalToBinary(int n) {
    if (n == 0) {
        return "0";
    }

    String binary = "";

    while (n > 0) {
        int bit = n % 2;
        binary = bit + binary;
        n = n / 2;
    }

    return binary;
}
```

Example:

```text
n = 13

13 % 2 = 1
13 / 2 = 6

6 % 2 = 0
6 / 2 = 3

3 % 2 = 1
3 / 2 = 1

1 % 2 = 1
1 / 2 = 0
```

Remainders came in this order:

```text
1, 0, 1, 1
```

But binary is written from last remainder to first remainder:

```text
13 = 1101
```

So the answer is:

```text
1101
```

Explanation:

- `% 2` gives the last bit.
- `/ 2` shifts the number right by one binary place.
- The loop stops when the number becomes `0`.
- If the original number is `0`, we directly return `"0"` because the loop will not run.

Time Complexity:

```text
O(log n)
```

Because each time we divide `n` by `2`, so the number of steps is equal to the number of binary digits.

Space Complexity:

```text
O(log n)
```

Because the binary string stores all bits of the number.

### 2. Check Whether the i-th Bit Is Set or Not

To check whether the `i-th` bit of a number is set, we use a bit mask.

A bit is called set if it is `1`.

The main idea:

```text
1 << i
```

This creates a mask where only the `i-th` bit is `1`.

Example:

```text
1 << 0 = 0001
1 << 1 = 0010
1 << 2 = 0100
1 << 3 = 1000
```

So if we want to check the `i-th` bit, we first create the mask:

```java
int mask = 1 << i;
```

Then we do AND with the original number:

```java
n & mask
```

If the result is not `0`, the bit is set.

If the result is `0`, the bit is not set.

```java
static boolean isBitSet(int n, int i) {
    int mask = 1 << i;
    return (n & mask) != 0;
}
```

Example:

```text
n = 10
```

Binary of `10`:

```text
10 = 1010
```

Now check whether bit `1` is set.

Create mask:

```text
1 << 1 = 0010
```

Now AND with original number:

```text
  1010
& 0010
------
  0010
```

Result is not `0`, so bit `1` is set.

```java
System.out.println(isBitSet(10, 1)); // true
```

Now check whether bit `2` is set.

Create mask:

```text
1 << 2 = 0100
```

Now AND with original number:

```text
  1010
& 0100
------
  0000
```

Result is `0`, so bit `2` is not set.

```java
System.out.println(isBitSet(10, 2)); // false
```

Explanation:

- `1 << i` creates a mask for the bit we want to check.
- `&` compares the mask with the original number.
- If the original number has `1` at that bit, the answer is non-zero.
- If the original number has `0` at that bit, the answer is zero.

Time Complexity:

```text
O(1)
```

Because we use a fixed number of bit operations.

Space Complexity:

```text
O(1)
```

Because we only create one extra variable, `mask`.

### 3. Make the i-th Bit a Set Bit

To make the `i-th` bit set, we need to turn that bit into `1`.

The main idea:

```text
Use OR with a mask.
```

First create a mask using:

```text
1 << i
```

This mask has only the `i-th` bit as `1`.

Then OR it with the original number:

```java
n | mask
```

Why OR?

```text
0 | 1 = 1
1 | 1 = 1
```

So OR guarantees that the selected bit becomes `1`.

```java
static int setBit(int n, int i) {
    int mask = 1 << i;
    return n | mask;
}
```

Example:

```text
n = 10
```

Binary of `10`:

```text
10 = 1010
```

Now make bit `2` a set bit.

Create mask:

```text
1 << 2 = 0100
```

Now OR with original number:

```text
  1010
| 0100
------
  1110
```

Result:

```text
1110 = 14
```

So:

```java
System.out.println(setBit(10, 2)); // 14
```

Another example:

```text
n = 10 = 1010
i = 1

1 << 1 = 0010

  1010
| 0010
------
  1010
```

Bit `1` was already set, so the number remains the same.

```java
System.out.println(setBit(10, 1)); // 10
```

Explanation:

- `1 << i` creates a mask for the bit we want to set.
- `|` is used because OR with `1` always gives `1`.
- If the bit was already `1`, it stays `1`.
- If the bit was `0`, it becomes `1`.

Time Complexity:

```text
O(1)
```

Because setting a bit takes one shift and one OR operation.

Space Complexity:

```text
O(1)
```

Because we only use one extra variable, `mask`.

### 4. Check the i-th Bit Using Right Shift

Pattern 2 checked the `i-th` bit by moving `1` to the `i-th` position:

```java
n & (1 << i)
```

There is another way to think about the same problem.

Instead of moving `1` to the `i-th` bit, we can move the `i-th` bit of `n` to the last position.

The main idea:

```text
n >> i
```

This shifts the number `i` times to the right.

After this, the original `i-th` bit comes to the `0-th` position, also called the last bit.

Then we check the last bit using:

```text
& 1
```

Code:

```java
static boolean isBitSetUsingRightShift(int n, int i) {
    return ((n >> i) & 1) != 0;
}
```

Important:

```java
((n >> i) & 1) != 0
```

This is correct.

Do not use:

```java
(n & (n >> i)) != 0
```

because that compares the original number with its shifted version. It does not directly check only the `i-th` bit.

Example:

```text
n = 10
```

Binary of `10`:

```text
10 = 1010
```

Now check whether bit `1` is set.

Shift `n` right by `1`:

```text
1010 >> 1 = 0101
```

Now check the last bit:

```text
  0101
& 0001
------
  0001
```

Result is not `0`, so bit `1` is set.

```java
System.out.println(isBitSetUsingRightShift(10, 1)); // true
```

Now check whether bit `2` is set.

Shift `n` right by `2`:

```text
1010 >> 2 = 0010
```

Now check the last bit:

```text
  0010
& 0001
------
  0000
```

Result is `0`, so bit `2` is not set.

```java
System.out.println(isBitSetUsingRightShift(10, 2)); // false
```

Both methods do the same thing:

```java
(n & (1 << i)) != 0
```

and:

```java
((n >> i) & 1) != 0
```

Memory trick:

```text
Left shift method:
Move the mask to the bit.

Right shift method:
Move the bit to the mask.
```

Explanation:

- `n >> i` brings the `i-th` bit to the last position.
- `& 1` checks whether the last bit is `1`.
- If the result is `1`, the original `i-th` bit was set.
- If the result is `0`, the original `i-th` bit was not set.

Time Complexity:

```text
O(1)
```

Because it uses one right shift and one AND operation.

Space Complexity:

```text
O(1)
```

Because no extra data structure is used.

### 5. Unset the i-th Bit

Unsetting a bit means making that bit `0`.

It is also called clearing a bit.

The goal:

```text
If the i-th bit is 1, make it 0.
If the i-th bit is already 0, keep it 0.
Keep all other bits unchanged.
```

The main idea:

```text
Make a mask where only the i-th bit is 0 and all other bits are 1.
Then AND it with the original number.
```

Step 1: Create a normal mask.

```java
int mask = 1 << i;
```

Example:

```text
i = 1

1 << 1 = 0010
```

Step 2: Take complement of the mask.

```java
mask = ~mask;
```

Now the selected bit becomes `0`, and all other bits become `1`.

```text
mask       = 0010
~mask      = 1101
```

Step 3: AND with the original number.

```java
n & mask
```

Why AND?

```text
1 & 0 = 0
0 & 0 = 0
1 & 1 = 1
0 & 1 = 0
```

So:

- AND with `0` forces the selected bit to become `0`.
- AND with `1` keeps all other bits unchanged.

Code:

```java
static int unsetBit(int n, int i) {
    int mask = 1 << i;
    mask = ~mask;
    return n & mask;
}
```

Short version:

```java
static int unsetBit(int n, int i) {
    return n & ~(1 << i);
}
```

Example:

```text
n = 10
```

Binary of `10`:

```text
10 = 1010
```

Now unset bit `1`.

Create mask:

```text
1 << 1 = 0010
```

Complement the mask:

```text
~0010 = 1101
```

Now AND with original number:

```text
  1010
& 1101
------
  1000
```

Result:

```text
1000 = 8
```

So:

```java
System.out.println(unsetBit(10, 1)); // 8
```

Another example:

```text
n = 10 = 1010
i = 2

1 << 2 = 0100
~0100 = 1011

  1010
& 1011
------
  1010
```

Bit `2` was already `0`, so the number remains the same.

```java
System.out.println(unsetBit(10, 2)); // 10
```

Memory trick:

```text
To set a bit:
Use OR with 1.

To unset a bit:
Use AND with 0.
```

But we only want one bit to become `0`, so we use:

```text
~(1 << i)
```

This gives:

```text
All bits 1, only i-th bit 0.
```

Explanation:

- `1 << i` creates a mask where only the `i-th` bit is `1`.
- `~(1 << i)` flips it, so only the `i-th` bit becomes `0`.
- `&` with this mask clears only the `i-th` bit.
- All other bits remain unchanged because they are ANDed with `1`.

Time Complexity:

```text
O(1)
```

Because clearing a bit takes one shift, one complement, and one AND operation.

Space Complexity:

```text
O(1)
```

Because we only use one extra variable, `mask`.

### 6. Check Odd or Even Using the Last Bit

To check whether a number is odd or even, we only need to look at the last bit.

The last bit is also called the LSB.

```text
LSB = Least Significant Bit
```

Look at numbers from `1` to `6`:

```text
Decimal   Binary   LSB   Type
1         001      1     Odd
2         010      0     Even
3         011      1     Odd
4         100      0     Even
5         101      1     Odd
6         110      0     Even
```

Pattern:

```text
Even numbers always have LSB = 0
Odd numbers always have LSB = 1
```

Why?

Binary place values are:

```text
8 4 2 1
```

All places except the last place are powers of `2`.

```text
8, 4, 2 are even
```

Only the last place has value:

```text
1
```

So the last bit decides whether the final number is odd or even.

If the last bit is `0`, no extra `1` is added:

```text
number is even
```

If the last bit is `1`, one extra `1` is added:

```text
number is odd
```

To check the last bit, use:

```java
n & 1
```

Because:

```text
1 = 0001
```

So `& 1` keeps only the last bit and makes all other bits `0`.

Code:

```java
static boolean isOdd(int n) {
    return (n & 1) == 1;
}
```

For even:

```java
static boolean isEven(int n) {
    return (n & 1) == 0;
}
```

Example 1:

```text
n = 5
```

Binary:

```text
5 = 0101
```

Now AND with `1`:

```text
  0101
& 0001
------
  0001
```

Result is `1`, so `5` is odd.

```java
System.out.println(isOdd(5)); // true
```

Example 2:

```text
n = 6
```

Binary:

```text
6 = 0110
```

Now AND with `1`:

```text
  0110
& 0001
------
  0000
```

Result is `0`, so `6` is even.

```java
System.out.println(isEven(6)); // true
```

Memory trick:

```text
Last bit 0 means even.
Last bit 1 means odd.
```

Or:

```text
n & 1 == 0  means even
n & 1 == 1  means odd
```

Explanation:

- `1` in binary is `0001`.
- `n & 1` checks only the last bit of `n`.
- If the last bit is `0`, the number is even.
- If the last bit is `1`, the number is odd.

Time Complexity:

```text
O(1)
```

Because checking odd/even takes one AND operation.

Space Complexity:

```text
O(1)
```

Because no extra data structure is used.

### 7. Remove the Rightmost Set Bit

This is one of the most important patterns in bit manipulation.

The pattern:

```java
n = n & (n - 1);
```

Meaning:

```text
n & (n - 1) removes the rightmost set bit of n.
```

A set bit means a bit whose value is `1`.

So this operation removes the rightmost `1` from the binary form of the number.

Example:

```text
n = 12
```

Binary of `12`:

```text
12 = 1100
```

Now:

```text
n - 1 = 11
```

Binary of `11`:

```text
11 = 1011
```

Now do AND:

```text
  1100   n
& 1011   n - 1
------
  1000
```

Result:

```text
1000 = 8
```

So:

```text
12 & 11 = 8
```

What happened?

```text
1100 became 1000
```

The rightmost set bit disappeared.

Original:

```text
1100
  ^
  rightmost set bit
```

After:

```text
1000
```

That rightmost `1` became `0`.

Why does this work?

When we subtract `1` from a number:

```text
The rightmost set bit becomes 0.
All bits after it become 1.
Bits before it stay the same.
```

Example:

```text
n     = 1100
n - 1 = 1011
```

Now compare:

```text
n     = 1100
n - 1 = 1011
```

The rightmost set bit in `n` becomes `0` in `n - 1`.

When we AND both:

```text
  1100
& 1011
------
  1000
```

That rightmost set bit gets removed.

Code:

```java
static int removeRightmostSetBit(int n) {
    return n & (n - 1);
}
```

Example:

```java
System.out.println(removeRightmostSetBit(12)); // 8
```

Very Important Use Case: Count Set Bits

In coding assessments, this pattern is often used to count how many `1`s are present in the binary form of a number.

Example:

```text
n = 13
```

Binary:

```text
13 = 1101
```

There are three set bits:

```text
1101
^ ^^
```

Answer:

```text
3
```

Instead of checking every bit one by one, we can repeatedly remove the rightmost set bit.

Code:

```java
static int countSetBits(int n) {
    int count = 0;

    while (n > 0) {
        n = n & (n - 1);
        count++;
    }

    return count;
}
```

Dry Run:

```text
n = 13
```

Binary:

```text
13 = 1101
```

First loop:

```text
n     = 1101   13
n - 1 = 1100   12

  1101
& 1100
------
  1100   12
```

One rightmost set bit removed.

```text
count = 1
n = 12
```

Second loop:

```text
n     = 1100   12
n - 1 = 1011   11

  1100
& 1011
------
  1000   8
```

Another rightmost set bit removed.

```text
count = 2
n = 8
```

Third loop:

```text
n     = 1000   8
n - 1 = 0111   7

  1000
& 0111
------
  0000   0
```

Another rightmost set bit removed.

```text
count = 3
n = 0
```

Now the loop stops.

Final answer:

```text
3
```

So:

```java
System.out.println(countSetBits(13)); // 3
```

Another Approach: Count While Converting Decimal to Binary

We can also count set bits while converting the decimal number to binary.

This uses the same idea from Pattern 1:

```text
n % 2 gives the last bit
n / 2 removes the last bit
```

So whenever `n % 2` gives `1`, we increase the count.

Code:

```java
static int countSetBitsByConversion(int n) {
    int count = 0;

    while (n > 0) {
        int bit = n % 2;

        if (bit == 1) {
            count++;
        }

        n = n / 2;
    }

    return count;
}
```

Shorter version:

```java
static int countSetBitsByConversion(int n) {
    int count = 0;

    while (n > 0) {
        count += n % 2;
        n = n / 2;
    }

    return count;
}
```

Dry Run:

```text
n = 13
```

Binary:

```text
13 = 1101
```

Now count while dividing by `2`:

```text
n = 13
13 % 2 = 1   count = 1
13 / 2 = 6

n = 6
6 % 2 = 0    count = 1
6 / 2 = 3

n = 3
3 % 2 = 1    count = 2
3 / 2 = 1

n = 1
1 % 2 = 1    count = 3
1 / 2 = 0
```

Now `n` becomes `0`, so the loop stops.

Final answer:

```text
3
```

Important difference between both approaches:

```text
Conversion approach:
Checks every binary digit.

n & (n - 1) approach:
Runs only for set bits.
```

Example:

```text
n = 1024
```

Binary:

```text
10000000000
```

Conversion approach checks all binary digits.

`n & (n - 1)` approach runs only once because there is only one `1`.

Why this is efficient:

The loop runs only as many times as there are set bits.

Example:

```text
n = 1024
```

Binary:

```text
10000000000
```

There is only one set bit, so the loop runs only once.

Memory trick:

```text
n & (n - 1)
removes the rightmost 1
```

Common interview uses:

- Count set bits.
- Check if a number is a power of two.
- Solve bit manipulation problems faster than checking every bit manually.

Power of Two Connection:

A power of two has exactly one set bit.

```text
1  = 0001
2  = 0010
4  = 0100
8  = 1000
16 = 10000
```

So if we remove the rightmost set bit, a power of two becomes `0`.

```java
static boolean isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

Example:

```text
n = 8

8     = 1000
8 - 1 = 0111

  1000
& 0111
------
  0000
```

So `8` is a power of two.

Time Complexity:

```text
O(number of set bits)
```

For counting set bits, the loop runs once for every `1` in the binary form.

In the worst case for an `int`, it can be treated as:

```text
O(32) = O(1)
```

Space Complexity:

```text
O(1)
```

Because only a few integer variables are used.

### 8. Swap Two Numbers Using XOR

XOR can be used to swap two numbers without using a third variable.

This works because of the most important XOR rules:

```text
x ^ x = 0
x ^ 0 = x
```

Meaning:

```text
Same numbers cancel out.
Anything XOR with 0 remains itself.
```

Code:

```java
static void swapUsingXor(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    System.out.println("a = " + a);
    System.out.println("b = " + b);
}
```

Example:

```text
a = 5
b = 3
```

Binary:

```text
5 = 0101
3 = 0011
```

Step 1:

```java
a = a ^ b;
```

Visual:

```text
  0101   a = 5
^ 0011   b = 3
------
  0110   a = 6
```

Now:

```text
a = 6
b = 3
```

But remember:

```text
a is actually holding a ^ b
```

So:

```text
a = old a ^ old b
```

Step 2:

```java
b = a ^ b;
```

Since `a` is currently `old a ^ old b`:

```text
b = (old a ^ old b) ^ old b
```

Now `old b` cancels with `old b`:

```text
b = old a ^ 0
b = old a
```

Visual:

```text
  0110   a = 6
^ 0011   b = 3
------
  0101   b = 5
```

Now:

```text
a = 6
b = 5
```

So `b` has received the old value of `a`.

Step 3:

```java
a = a ^ b;
```

Now:

```text
a = old a ^ old b
b = old a
```

So:

```text
a = (old a ^ old b) ^ old a
```

Now `old a` cancels with `old a`:

```text
a = old b ^ 0
a = old b
```

Visual:

```text
  0110   a = 6
^ 0101   b = 5
------
  0011   a = 3
```

Final result:

```text
a = 3
b = 5
```

The numbers are swapped.

Full dry run:

```text
Start:
a = 5
b = 3

a = a ^ b
a = 5 ^ 3 = 6

b = a ^ b
b = 6 ^ 3 = 5

a = a ^ b
a = 6 ^ 5 = 3

End:
a = 3
b = 5
```

Memory trick:

```text
XOR stores mixed information.
XOR again with one original value gives the other value back.
```

Why?

```text
(a ^ b) ^ b = a
(a ^ b) ^ a = b
```

Important warning:

Do not use XOR swap when both variables refer to the same memory location.

For normal Java local variables like this:

```java
int a = 5;
int b = 3;
```

it works.

But in real code, this is usually clearer:

```java
int temp = a;
a = b;
b = temp;
```

Use XOR swap mainly to understand XOR deeply and for interview bit manipulation practice.

Time Complexity:

```text
O(1)
```

Because swapping takes three XOR operations.

Space Complexity:

```text
O(1)
```

Because no extra variable is used.

### 9. Count Number of Bit Flips to Convert `a` to `b`

This is a very important bit manipulation pattern.

Problem:

```text
Given two numbers a and b, count how many bits need to be flipped to convert a into b.
```

Example:

```text
a = 10
b = 7
```

Binary:

```text
10 = 1010
7  = 0111
```

Compare bit by bit:

```text
  1010
  0111
  ^ ^^
```

Different bits = `3`

So answer:

```text
3
```

#### Naive Approach: Convert Both Numbers to Binary Strings

In this approach:

1. Convert `a` to binary string.
2. Convert `b` to binary string.
3. Add leading zeros so both strings have the same length.
4. Compare both strings character by character.
5. Count positions where bits are different.

Code:

```java
static int findMinBits(int a, int b) {
    String x = "";
    String y = "";

    while (a > 0) {
        int bit = a % 2;
        x = bit + x;
        a = a / 2;
    }

    while (b > 0) {
        int bit = b % 2;
        y = bit + y;
        b = b / 2;
    }

    if (x.isEmpty()) {
        x = "0";
    }

    if (y.isEmpty()) {
        y = "0";
    }

    int maxLen = Math.max(x.length(), y.length());
    x = String.format("%" + maxLen + "s", x).replace(' ', '0');
    y = String.format("%" + maxLen + "s", y).replace(' ', '0');

    int diff = 0;

    for (int i = 0; i < maxLen; i++) {
        if (x.charAt(i) != y.charAt(i)) {
            diff++;
        }
    }

    return diff;
}
```

Dry Run:

```text
a = 10
b = 7
```

Convert `a` to binary:

```text
10 % 2 = 0
10 / 2 = 5

5 % 2 = 1
5 / 2 = 2

2 % 2 = 0
2 / 2 = 1

1 % 2 = 1
1 / 2 = 0
```

So:

```text
a = 1010
```

Convert `b` to binary:

```text
7 % 2 = 1
7 / 2 = 3

3 % 2 = 1
3 / 2 = 1

1 % 2 = 1
1 / 2 = 0
```

So:

```text
b = 111
```

Now both strings must have the same length.

```text
a = 1010
b = 111
```

Pad `b` with one leading zero:

```text
a = 1010
b = 0111
```

Now compare:

```text
  1010
  0111
  ^ ^^
```

Different bits:

```text
3
```

So:

```java
findMinBits(10, 7) = 3
```

Why padding is needed:

```text
1010 and 111 are not aligned properly.
1010 and 0111 are aligned properly.
```

Leading zeros do not change the value.

```text
111 = 0111 = 00111
```

Time Complexity:

```text
O(log a + log b)
```

Because we convert both numbers to binary strings and then compare the bits.

Space Complexity:

```text
O(log a + log b)
```

Because we store both binary strings.

#### Optimal Approach: XOR and Count Set Bits

This is the important interview approach.

Main idea:

```text
XOR gives 1 wherever bits are different.
```

XOR rule:

```text
same bits      -> 0
different bits -> 1
```

So:

```text
a ^ b
```

creates a number whose set bits show exactly where `a` and `b` are different.

Then the answer is:

```text
number of set bits in (a ^ b)
```

Code:

```java
static int findMinBitsOptimal(int a, int b) {
    int xor = a ^ b;
    int count = 0;

    while (xor > 0) {
        xor = xor & (xor - 1);
        count++;
    }

    return count;
}
```

Dry Run:

```text
a = 10
b = 7
```

Binary:

```text
a = 1010
b = 0111
```

XOR:

```text
  1010
^ 0111
------
  1101
```

So:

```text
a ^ b = 1101
```

Now count set bits in `1101`.

There are three `1`s:

```text
1101
^ ^^
```

Answer:

```text
3
```

Now dry run using `xor & (xor - 1)`:

```text
xor = 1101
count = 0
```

First loop:

```text
xor       = 1101   13
xor - 1   = 1100   12

  1101
& 1100
------
  1100
```

```text
count = 1
xor = 1100
```

Second loop:

```text
xor       = 1100   12
xor - 1   = 1011   11

  1100
& 1011
------
  1000
```

```text
count = 2
xor = 1000
```

Third loop:

```text
xor       = 1000   8
xor - 1   = 0111   7

  1000
& 0111
------
  0000
```

```text
count = 3
xor = 0
```

Loop stops.

Final answer:

```text
3
```

Even shorter Java version:

```java
static int findMinBitsOptimal(int a, int b) {
    return Integer.bitCount(a ^ b);
}
```

Memory trick:

```text
Minimum bit flips from a to b
= count different bits
= count 1s in (a ^ b)
```

Or simply:

```text
flip count = set bit count of XOR
```

Why XOR is perfect here:

```text
If bits are same, no flip needed -> XOR gives 0.
If bits are different, flip needed -> XOR gives 1.
```

Time Complexity:

```text
O(number of set bits in a ^ b)
```

In the worst case for an `int`:

```text
O(32) = O(1)
```

Space Complexity:

```text
O(1)
```

Because we only use integer variables.

### 10. Find the Rightmost Set Bit Mask

This pattern is about finding only the rightmost `1` bit of a number.

The result should be a mask.

Meaning:

```text
Original number:       00001100
Rightmost set bit:     00000100
```

So for:

```text
n = 12
```

Binary:

```text
12 = 00001100
```

The rightmost set bit is:

```text
00000100
```

As decimal:

```text
4
```

#### Approach 1: Manual Method Using Loop

In this approach, we keep dividing the number by `2` until we find the first `1` bit from the right side.

Why from the right side?

Because:

```text
n % 2 gives the last bit.
n / 2 removes the last bit.
```

So we can count how many `0`s appear before the first `1`.

That count is the position of the rightmost set bit.

Code:

```java
// Finds the rightmost set bit of n and returns its 8-bit binary mask.
// Example: n = 12 -> 00001100, rightmost set bit mask -> 00000100.
// If n is 0, there is no set bit, so it returns 00000000.
static String findRightmostSetBitMask(int n) {
    if (n == 0) {
        return "00000000";
    }

    int counter = 0;
    int temp = n;

    while (temp > 0) {
        int bit = temp % 2;

        if (bit == 1) {
            break;
        }

        counter++;
        temp = temp / 2;
    }

    int mask = 1 << counter;

    return String.format("%8s", Integer.toBinaryString(mask)).replace(' ', '0');
}
```

Dry Run:

```text
n = 12
```

Binary:

```text
12 = 00001100
```

Start:

```text
counter = 0
temp = 12
```

First loop:

```text
temp = 12
12 % 2 = 0
```

Last bit is `0`, so this is not the rightmost set bit.

```text
counter = 1
temp = 12 / 2 = 6
```

Second loop:

```text
temp = 6
6 % 2 = 0
```

Again last bit is `0`.

```text
counter = 2
temp = 6 / 2 = 3
```

Third loop:

```text
temp = 3
3 % 2 = 1
```

Now we found the first `1` from the right side, so stop.

```text
counter = 2
```

Now create the mask:

```text
1 << counter
1 << 2
```

Visual:

```text
00000001 << 2 = 00000100
```

So the answer:

```text
00000100
```

Memory trick:

```text
Count zeros from the right until first 1.
Then do 1 << count.
```

#### Approach 2: Optimal Method Using `n & -n`

The fastest way to get the rightmost set bit mask is:

```java
static int findRightmostSetBit(int n) {
    return n & -n;
}
```

This returns the mask in decimal form.

Example:

```text
n = 12
```

Binary:

```text
n = 00001100
```

Result:

```text
n & -n = 00000100
```

Decimal:

```text
4
```

#### Why `n & -n` Works

Java stores negative numbers using two's complement.

To get `-n`:

```text
1. Flip all bits of n.
2. Add 1.
```

Example:

```text
n = 12
```

Using 8-bit view:

```text
n = 00001100
```

Step 1: Flip all bits.

```text
~n = 11110011
```

Step 2: Add `1`.

```text
11110011
+      1
--------
11110100
```

So:

```text
-n = 11110100
```

Now AND `n` and `-n`:

```text
  00001100   n
& 11110100   -n
--------
  00000100
```

Only the rightmost set bit remains.

Why only that bit remains?

```text
All bits to the right of the rightmost 1 are 0 in n.
The rightmost 1 stays 1 in both n and -n.
The bits to the left do not survive the AND in this pattern.
```

So:

```text
n & -n keeps only the rightmost 1.
```

#### Return as 8-bit Binary String

If we want the optimal method but still want output like `00000100`, use:

```java
static String findRightmostSetBitMaskOptimal(int n) {
    if (n == 0) {
        return "00000000";
    }

    int mask = n & -n;
    return String.format("%8s", Integer.toBinaryString(mask)).replace(' ', '0');
}
```

Example:

```java
System.out.println(findRightmostSetBitMask(12));        // 00000100
System.out.println(findRightmostSetBit(12));            // 4
System.out.println(findRightmostSetBitMaskOptimal(12)); // 00000100
```

Important difference:

```text
Position tells where the bit is.
Mask gives a number with only that bit turned on.
```

Example:

```text
n = 12 = 00001100

Rightmost set bit position = 2
Rightmost set bit mask     = 00000100
Rightmost set bit decimal  = 4
```

Memory trick:

```text
n & -n
keeps only the rightmost set bit
```

Time Complexity:

```text
O(1)
```

For the optimal `n & -n` method.

The manual loop takes:

```text
O(number of trailing zeros)
```

Space Complexity:

```text
O(1)
```

Because only a few variables are used.

## Practice More Bit Manipulation Questions

For more practice, revise and solve bit manipulation problems from:

```text
Pepcoding Bit Manipulation Playlist:
https://www.youtube.com/playlist?list=PL-Jc9J83PIiFJRioti3ZV7QabwoJK6eKe
```

Also practice bit manipulation questions from the Striver platform.

Revision reminder:

```text
Do not only watch solutions.
First try to identify the pattern:

1. Is it asking about different bits? Think XOR.
2. Is it asking about the i-th bit? Think mask: 1 << i.
3. Is it asking to remove/count set bits? Think n & (n - 1).
4. Is it asking for rightmost set bit mask? Think n & -n.
```
