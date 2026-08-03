class Lecture06 {
    public static void main(String[] args) {
        int n = 10;
        int count = countSetBits(n);
        System.out.println(count);
        
        int result = findMinBits(10, 7);
        System.out.println(result);

        System.out.println(findRightmostSetBitMask(12));
        System.out.println(findRightmostSetBit(12));
    }

    // code to convert decimal val into bits
    static int countSetBits(int n) {
        int count = 0;
        while (n >= 1) {
            int bit = n % 2;
            if (bit == 1) {
                count++;
            }
            n = n / 2;
        }
        return count;
    }

    // code to find Minimum Bit Flips to Convert Number
    static int findMinBits(int a, int b){
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

    static int findRightmostSetBit(int n) {
        return n & -n;
    }
}


