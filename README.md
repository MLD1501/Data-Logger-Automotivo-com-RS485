# Data-Logger-Automotivo-com-RS485

No mundo atual, a emissão de poluentes na atmosfera é algo preocupante, um dos maiores impulsionadores de tal problema são os veículos movidos a motores a combustão interna (	MCI). Tecnologias aplicadas neste tipo de máquina surgem na tentativa de torná-las mais eficientes, diminuindo o consumo de combustível e elevando a potência disponível. Apresenta-se neste trabalho o desenvolvimento de um equipamento para coleta de dados de baixo custo, que tem como objetivo disponibilizar de forma eficiente alguns dados relevantes para o bom funcionamento de motores a combustão interna do tipo ciclo Otto quatro tempos. Inspirado na topologia de hardware distribuído aplicado em diversos veículos, os quais utilizam protocolo CAN (Controller Area Network), este trabalho utiliza rede RS485, tornando o hardware resistente a interferência eletromagnética e à queda de tensão ocasionada pelo comprimento de cabos. A comunicação entre devices (conjunto de hardware e sensor) e interface humana foi realizada utilizando o protocolo ICSC (Inter-Chip Serial Communications), projeto open source disponível no GitHub que garante a integridade dos pacotes trafegados no barramento. Foram realizados testes em um motor VolksWagen 1500 Boxer, constatando-se viabilidade no projeto, proporcionando dados precisos com poucas perdas e pouco defasados, de acordo com baud rate selecionado e às medidas tomadas no desenvolvimento do hardware e firmware.  

Palavras-chave: Data Logger. Comunicação RS485. Motores a Combustão Interna. Protocolo CAN. Arquitetura Distribuída. 

In today's world, emissions of pollutants into the atmosphere are something of concern, one of the biggest drivers of such a problem are vehicles powered by internal combustion engines. Technologies applied to this type of machine is an attempt to make them more efficient, reducing fuel consumption and increasing available power. This work presents the development of a low-cost data logger, which aims to efficiently provide some relevant data for the proper functioning of four-stroke Otto cycle internal combustion engines. Inspired by the distributed hardware topology applied in several vehicles, which use CAN (Controller Area Network) protocol, an RS485 network was used, making the hardware resistant to electromagnetic interference and the voltage drop caused by the length of cables. The communication between devices (hardware and sensor) and human interface was performed using the ICSC (Inter-Chip Serial Communications) protocol, an open-source project available on GitHub that guarantees the integrity of the packets transmitted on the bus. Tests were carried out on a VolksWagen 1500 Boxer engine, verifying the feasibility of the project, providing accurate data with few losses and little lag, due to the selected baud rate and measures taken in the development of hardware and firmware. 

Key-words: Data Logger. Communication RS485. Internal Combustion Engines. CAN Protocol. Distributed Architecture. 
