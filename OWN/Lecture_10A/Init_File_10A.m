%Real time Workshop Constants
Sample_Time = 0.001;%seconds
PWM_Period = 1/20000;%seconds

%Low Pass Filter Constants
R = 10000; %Ohms
C = 0.1e-6;%Farads

%Motor and Generator Constants
Motor_Inertia = 4.378e-6; %kg*m^2
Torque_Constant = 9.1; %Oz_in per amp
Motor_Rated_Current = 4;%Amps
Generator_Inertia = 4.378e-6;%kg*m^2
Generator_Voltage_Gain = 24/3500;%Volts per amp

%Load Constants
Bulb_R = 12; %^Standart 12V automotive bulb (Ohms)

%Encoder Constant
Encoder_Gain = 2.5/1000;%Volts per rpm

%Flywhell Inertia
Flywheel_Inertia = 1.041e-4;

%Coast down friction Coefficients
P1 = 0.0113;
P2 = 0.6374;

%Gain controller
P_Gain = 54.3433;
I_Gain = 14.776;