public class FlourPacker {
    public static final int BIG = 5;
    public static final int SMALL = 1;

    public static boolean canPack(int bigCount, int smallCount, int goal) {
        int sum = 0;
        int temp = 0;

        if (bigCount < 0 || smallCount < 0)
            return (false);

        while (bigCount > 0 ) {

            if (sum + BIG > goal)
                break;
            sum += BIG;
            bigCount--;
            if (sum == goal)
                return (true);
        }

        while (smallCount > 0) {

            if (sum + SMALL > goal)
                break;
            sum += SMALL;
            smallCount--;
            if (sum == goal)
                return (true);
        }
        return (false);
    }
}
