## Lecture 2: JVM, JRE, JDK + Compiler, Interpreter, JIT

### 1. Basic flow of Java program

Java code does not directly become machine code.

```text
Hello.java  →  Java Compiler  →  Hello.class  →  JVM  →  Machine Code  →  Output
Source Code       javac          Bytecode
```

First, Java uses a **compiler** to convert source code into **bytecode**.

Then, the **JVM** runs that bytecode on your computer.

---

### 2. Compiler vs Interpreter

A **compiler** translates the whole program at once before running it.

```text
Source Code → Machine Code → Run
```

An **interpreter** translates and runs code step by step, usually line by line.

```text
Source Code → Translate one part → Run → Next part
```

---

### 3. Is Java compiled or interpreted?

Java is **both compiled and interpreted**.

First:

```text
.java file → Compiler → .class file / Bytecode
```

Then:

```text
Bytecode → JVM Interpreter → Machine Code
```

So Java is called both:

* **compiled**, because `.java` becomes bytecode.
* **interpreted**, because JVM reads and runs bytecode.

---

### 4. What is JIT Compiler?

JIT means **Just-In-Time Compiler**.

Inside JVM, some bytecode is interpreted first. But if the JVM notices that some code is used again and again, it sends that frequent code to the **JIT compiler**.

JIT converts that frequent bytecode into machine code once, so it can run faster next time.

```text
Bytecode → Interpreter → runs normally

Frequently used bytecode → JIT Compiler → Machine Code → faster execution
```

---

### 5. JVM, JRE, JDK

### JVM — Java Virtual Machine

JVM runs Java bytecode.

It converts bytecode into machine code for the current platform.

### JRE — Java Runtime Environment

JRE is used to **run** Java programs.

```text
JRE = JVM + Java class libraries
```

It includes things needed during execution, like console output, file reading, memory handling, etc.

### JDK — Java Development Kit

JDK is used to **develop and run** Java programs.

```text
JDK = JRE + development tools
```

It includes:

* compiler `javac`
* debugger
* other development tools

---

### Simple relationship

```text
JDK
 └── JRE
      └── JVM
```

So:

* To **run** Java programs → need **JRE**
* To **write and compile** Java programs → need **JDK**
* To **execute bytecode** → need **JVM**
