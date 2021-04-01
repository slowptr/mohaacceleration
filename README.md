# mohaacceleration
implementations of various mouse acceleration algorithms into MOH(AA/SH)'s CL_MouseMove function
```
the "mod" implements following commands:
  cl_mouseAccelOption       [0-4]
  cl_mouseAccelOffset       [float]
  cl_mouseAccelPower        [2=linear]
  cl_mouseAccelThreshold    [float]
  sensitivity_scale_x       [float]
  sensitivity_scale_y       [float]
  
  
cl_mouseAccelOption explanation:
    0: default mohaa accel style
    1: interaccel / classic style
    2: tauntyarmordillo's natural accel (threshold relevant)
    3: natural logarithmic accel
    4: source style acceleration
```
