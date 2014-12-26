i = 0
cont = 65
k = 0
campeao = 0
jogos = [];
jogos2 = [];
jogos3 = [];

while(i<15):
	gamb = raw_input();	#GAMBIARRA
	gamb = gamb.split(' '); #GAMBIARRA
	m = int(gamb[0]);
	n = int(gamb[1]);
	if(i<8):
		if(m>n):
			jogos.append(cont);
		else:
			jogos.append(cont+1);
		cont = cont+2;
	elif(8<=i<12):
		if(m>n):
			jogos2.append(jogos[cont]);
		else:
			jogos2.append(jogos[cont+1]);
		cont = cont + 2;
	elif(12<=i<14):
		if(m>n):
			jogos3.append(jogos2[cont]);
		else:
			jogos3.append(jogos2[cont+1]);
		cont = cont + 2;
	elif(i==14):
		if(m>n):
			campeao = jogos3[0];
		else:
			campeao = jogos3[1];
	i= i+1;
	if(i==8 or i==12):
		cont=0;

print "%c" %(chr(campeao));	
		
