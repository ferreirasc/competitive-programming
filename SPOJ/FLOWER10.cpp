    #include <cstdio>
    #include <string>
     
    char input,aux,current;
    int contador;
    bool tauto = true;
     
    int main(){
            //freopen("exemplo.txt","r",stdin);
     
            input = ' ';
            contador = -1;
     
            while(input != '*'){
     
                    scanf("%c", &input);
     
                    if(input == '*') break;
     
                    if(contador == -1){
                            current = input;
                            aux = current;
                            contador = 0;
                    }
     
                    if(contador > 0) {
                            aux = current;
                            current = input;
                    }
     
                    if(contador && (tolower(current) != tolower(aux))) tauto = false;
     
                    if(contador == 1) contador = 0;
     
                    if(input == ' '){
                            contador = 1;
                    }
     
                    if(input == '\n'){
                            if(tauto) printf("Y\n");
                            else printf("N\n");
                            contador = -1;
                            tauto = true;
                    }
            }
     
            //while(1);
            return 0;
    }
