
package precisaovaloresmonetarios;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;

/**
 *
 * @author lazar
 */
public class PrecisaoValoresMonetarios {    
    public static void main(String[] args) {       
        double NotaFical_a = 53444.1111;
        double NotaFical_b = 2433.3333;  
        
        BigDecimal resultado_subtracao = new BigDecimal(Double.toString(NotaFical_a)).subtract
        (new BigDecimal(Double.toString(NotaFical_b)).setScale(6, RoundingMode.HALF_UP)); 
        /* setScale define o número de digitos a considerar depois da vírgula. 
        A precisão considera a escala definida mais os digitos antes da vírgula*/
        BigDecimal resultado_divisao = new BigDecimal(Double.toString(NotaFical_a)).divide
        (new BigDecimal(Double.toString(NotaFical_b)), 6, RoundingMode.HALF_UP );
        
        BigDecimal resultado_multiplicacao = new BigDecimal(Double.toString(NotaFical_a)).multiply
        (new BigDecimal(Double.toString(NotaFical_b)).setScale(6, RoundingMode.HALF_UP)); 

        BigDecimal resultado_soma = new BigDecimal(Double.toString(NotaFical_a)).add
        (new BigDecimal(Double.toString(NotaFical_b)).setScale(6, RoundingMode.HALF_UP)); 
        
        BigDecimal resultado_potenciacao = new BigDecimal(Double.toString(NotaFical_a)).pow
        (2, MathContext.UNLIMITED);

        
         System.out.printf("Subtracao: %.2f \n",resultado_subtracao);
         System.out.printf("Divisao: %.2f \n",resultado_divisao);    
         System.out.printf("Soma: %.2f \n",resultado_soma);
         System.out.printf("Multiplicacao: %.2f \n",resultado_multiplicacao);
         System.out.printf("Potenciacao: %.2f \n",resultado_potenciacao); 
         
         System.out.printf("Precisao da subtracao: %d \n",resultado_subtracao.precision());
         System.out.printf("Precisao da divisao: %d \n",resultado_divisao.precision());
         System.out.printf("Precisao da soma: %d \n",resultado_soma.precision());
         System.out.printf("Precisao da multiplicacao: %d \n",resultado_multiplicacao.precision());
         System.out.printf("Precisao da potenciacao: %d \n",resultado_potenciacao.precision());
         
    }    
}