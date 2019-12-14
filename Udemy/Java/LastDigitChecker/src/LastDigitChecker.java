public class LastDigitChecker {
    public static boolean hasSameLastDigit(int firstNumber, int secondNumber, int thirdNumber) {
        if(isValid(firstNumber) && isValid(secondNumber) && isValid(thirdNumber)) {
            int x = firstNumber % 10;
            int y = secondNumber % 10;
            int z = thirdNumber % 10;
            return (x == y || x == z || y == z);
        } else {
            return false;
        }
    }

    public static boolean isValid(int number) {
        if(number >= 10 && number<=1000){
            return true;
        } else {
            return false;
        }
    }
}
