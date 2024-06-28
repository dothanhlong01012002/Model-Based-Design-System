%Find the rise time.

%Calculate the Rise Time


% Define the rise time as the amount of time it takes the
% output got go from 10% of the final value to 90%
% of the final value.

Ten_Pct_Value = 0.1*Speed_Step;
Ninety_Pct_Value = 0.9*Speed_Step;
Ten_Pct_Time = 0;
Ninety_Pct_Time = 0;


%Find the time of the 10% Point.
for i = 1: (length(time)-1)
    if (Scaled_RPM_Signal (i) <= Ten_Pct_Value)  &&...
            (Scaled_RPM_Signal (i+1) >= Ten_Pct_Value)
        Ten_Pct_Time=time(i);
    end

%Find the time of the 90% Point.    
    
    if (Scaled_RPM_Signal (i) <= Ninety_Pct_Value)  &&...
            (Scaled_RPM_Signal (i+1) >= Ninety_Pct_Value)
        Ninety_Pct_Time=time(i);
    end
end

% Calculate the rise time as the difference between the 
% 10% and 90% points. If a rise time is not found, set the
% Rise_Time to infinity.

if  (Ten_Pct_Time > 0) &&  (Ninety_Pct_Time > 0)
    Rise_Time = Ninety_Pct_Time-Ten_Pct_Time;
else
    Rise_Time = inf;
end



