cinco=0
i = 1
cinq = 0
um = 0
dez = 0

while(1):
	valor = int(raw_input());
	if(valor==0):
		break;
	else:
	        while((valor/50) != 0):
			cinq = int(valor/50);
			valor = valor % 50;
		while((valor/10) != 0):
			dez = int(valor/10);
			valor = valor % 10;
		while((valor/5) != 0):
			cinco = int(valor/5);
			valor = valor % 5;
		while((valor/1) != 0):
			um = int(valor/1);
			valor = valor % 1;
		print "Teste %d" % i;
		print "%d %d %d %d" %(cinq, dez, cinco, um); 
		cinq = dez = cinco = um = 0;
		i=i+1;	
