public class SharedDigit {
    public static boolean hasSharedDigit(int firstNumber, int secondNumber) {
        int lastNumber = 0;
        if ((firstNumber < 10 || firstNumber > 99) || (secondNumber < 10 || secondNumber > 99)) {
            return false;
        }
        int x = firstNumber % 10;
        int y = secondNumber % 10;
        firstNumber /= 10;
        secondNumber /= 10;
        return (firstNumber == secondNumber || firstNumber == y || secondNumber == x || x == y);
    }
}
