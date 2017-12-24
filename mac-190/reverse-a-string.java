import java.util.Scanner;
public class Reverse {
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        
        String sentence, reverse="";
        int i;
        
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a string");
        sentence = input.nextLine();
        
        int length = sentence.length();
        int n = (length - 1);
        
        for(i=n; i>=0; i--){
            
            reverse = reverse + sentence.charAt(i);
        }
        
        System.out.print(reverse);
        
    }
    
}
