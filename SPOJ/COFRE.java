    import java.util.*;  
    class deposito {  
        public static void main(String[] args) {  
            Scanner scan = new Scanner(System.in);  
            int depositos=1,neto1=0,neto2=0,cont=0,roda=0,n=0;  
            int vet[]=new int [100];  
            while((roda=depositos=scan.nextInt())!=0){  
                n++;  
                cont=0;  
                while(depositos>0){  
                    neto1=neto1+scan.nextInt();  
                    neto2=neto2+scan.nextInt();  
                    vet[cont]=neto1-neto2;  
                    depositos--;  
                    cont++;  
                }  
                cont=neto1=neto2=0;  
                System.out.println("Teste "+n);  
                while(roda!=0){  
                    System.out.println(vet[cont]);  
                    vet[cont]=0;  
                    cont++;  
                    roda--;  
                }  
            }System.out.println("");  
        }  
    }  