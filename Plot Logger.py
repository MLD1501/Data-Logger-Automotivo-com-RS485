import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

#Carrega CSV
dataset = pd.read_csv("Data", parse_dates=['id', 'value'])
dataset = dataset.astype(int)
print(dataset)

#Convertendo variáveis de tensão para unidades específicas
s1 = (dataset.loc[dataset['id'] == 1]*0.00488) #Valor lambda
s2 = (-0.0955*dataset.loc[dataset['id'] == 2]) + 109.89
R_Sensor_Temperatura = (470/dataset.loc[dataset['id'] == 3])*(1023-dataset.loc[dataset['id'] == 3]) #Calculando resistencia do sensor com divisor de tensão
s3 = -27.41*np.log(R_Sensor_Temperatura)+244.72 #Convertendo valor de resistencia para temperatura
s4 = 100*dataset.loc[dataset['id'] == 4] #Valor rotação

#Plotando gráficos
plt.suptitle('Data Logger RS485')

plt.subplot(411)
plt.ylabel('Lambda [mV]', color='red')
plt.plot(s1['value'], color='red')
plt.grid()
#plt.yticks(range(0,1.2,.2))

plt.subplot(412)
plt.ylabel('MAP[KPa]', color='blue')
plt.plot(s2['value'], color='blue')
plt.grid()
plt.yticks(range(17,105,10))

plt.subplot(413)
plt.ylabel('Temperatura[°C]', color='green')
plt.plot(s3['value'], color='green')
plt.grid()
#plt.yticks(range(0,125,1))

plt.subplot(414)
plt.ylabel('Rotação[RPM]', color='orange')
plt.plot(s4['value'], color='orange')
plt.grid()
plt.yticks(range(0,5000,500))

plt.show()

