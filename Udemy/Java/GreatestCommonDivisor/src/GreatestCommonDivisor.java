public class GreatestCommonDivisor {
    public static int getGreatestCommonDivisor(int first, int second) {
        int gcd = 0;
        if(first < 10 || second < 10) {
            return -1;
        } else {
            for(int i = 1; i <= first && i<= second; i++) {
                if (first %i ==0 && second %i ==0){
                    gcd = i;
                }
            }
        }

        return gcd;
    }
}
