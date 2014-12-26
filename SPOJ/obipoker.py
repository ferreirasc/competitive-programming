n = int(raw_input());
cartas = []
achou = 1;
j = 1

for i in range(n):
	comp = raw_input();
	comp = comp.split();
	for i in range(5):
		cartas.append(int(comp[i]));
	
	cartas.sort();
	pontos = 0;

	#Caso 1
	for i in range(5):
		if(cartas[0]+i != cartas[i]):
			achou = 0;
			break;	
	
	if(achou == 1):
		pontos = cartas[0]+200;
		print "Teste %d" %j
		print "%d\n" %(pontos);
		cartas = []
		j = j+1;
		continue;
	
	#Caso 2
	if((cartas[0]==cartas[1] and cartas[1]==cartas[2] and cartas[2] == cartas[3]) or (cartas[1]==cartas[2] and cartas[2]==cartas[3] and cartas[3]==cartas[4])):
		achou = 1;
	if(achou == 1):
		pontos = cartas[2]+180;
		print "Teste %d" %j
		print "%d\n" %(pontos);
		cartas = []
		j = j+1
		continue;	
	
	#Caso 3
	if((cartas[0]==cartas[1] and cartas[1]==cartas[2] and cartas[3] == cartas[4]) or (cartas[0]==cartas[1] and cartas[2]==cartas[3] and cartas[3]==cartas[4])):
		achou = 1;
	if(achou == 1):
		pontos = cartas[2]+160;
		print "Teste %d" %j
		print "%d\n" %(pontos);
		cartas = []
		j = j+1
		continue;

	#Caso 4
	if((cartas[0]==cartas[1] and cartas[1]==cartas[2] and cartas[3] != cartas[4]) or (cartas[0] != cartas[1] and cartas[2]==cartas[3] and cartas[3]==cartas[4])):
		achou = 1;
	if(achou == 1):
		pontos = cartas[2]+140;
		print "Teste %d" %j		
		print "%d\n" %(pontos);
		cartas = []
		j = j+1;
		continue;

	#Caso 5
	if(cartas[0] == cartas[1] and cartas[2] == cartas[3]):
		if(cartas[0]>cartas[2]):
			pontos = 3*cartas[0] + cartas[2]*2 + 20;
			achou = 1;
		else:
			pontos = 3*cartas[2] + cartas[0]*2 + 20;
			achou = 1;

	elif(cartas[1] == cartas[2] and cartas[3] == cartas[4]):
		if(cartas[1]>cartas[3]):
			pontos = 3*cartas[1] + cartas[3]*2 + 20;
			achou = 1;
		else:
			pontos = 3*cartas[3] + cartas[1]*2 + 20;
			achou = 1;

	elif(cartas[0] == cartas[1] and cartas[3] == cartas[4]):
		if(cartas[0]>cartas[3]):
			pontos = 3*cartas[0] + cartas[3]*2 + 20;
			achou = 1;
		else:
			pontos = 3*cartas[3] + cartas[0]*2 + 20;
			achou = 1;
		
	if(achou == 1):
		print "Teste %d" %j
		print "%d\n" %(pontos);
		cartas = []
		j = j+1		
		continue;
	
	#Caso 6
	if(cartas[0] == cartas[1]):
		pontos = cartas[0];
		achou = 1;
	if(cartas[1] == cartas[2]):
		pontos = cartas[1];
		achou = 1;
	if(cartas[2] == cartas[3]):
		pontos = cartas[2];
		achou = 1;
	if(cartas[3] == cartas[4]):
		pontos = cartas[3];
		achou = 1;
	if(achou == 1):
		print "Teste %d" %j
		print "%d\n" %(pontos);
		cartas = []
		j = j+1
		continue;
	
	#Caso 7
	print "Teste %d" %j
	print "%d\n" %(pontos);
	cartas = [];
	j = j+1;
	continue;
