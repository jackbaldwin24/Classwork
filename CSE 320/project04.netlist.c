
/******************************************************************************
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  Pulser ((SD("2a"), "i: Init"), Init, 'i', 10000);
  Pulser ((SD("3a"), "c: Clock"), Clock, 'c', 10000);

  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  Probe ((SD("1c"), "w"), w);
  Probe ((SD("2c"), "x"), x);
  Probe ((SD("3c"), "y"), y);
  Probe ((SD("4c"), "z"), z);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  Signal notw, notx, noty, notz, and1, and2, and3, and4, and5, and6, W, X, Y, Z;

  Dff ((SD(sd, "2d"), "Dff3"), (Init, W, Clock, Zero), w);
  Dff ((SD(sd, "2d"), "Dff2"), (Zero, X, Clock, Init), x);
  Dff ((SD(sd, "2d"), "Dff1"), (Init, Y, Clock, Zero), y);
  Dff ((SD(sd, "2d"), "Dff0"), (Zero, Z, Clock, Init), z);

  Not ( SD(sd, "2d"), w, notw);
  Not ( SD(sd, "2d"), x, notx);
  Not ( SD(sd, "2d"), y, noty);
  Not ( SD(sd, "2d"), z, notz);

  And ( SD(sd, "2d"), (y, z), and1);
  And ( SD(sd, "2d"), (notw, notx, y), and2);  
  Or  ( SD(sd, "2d"), (and1, and2), W);

  And ( SD(sd, "2d"), (noty, z), and3);  
  And ( SD(sd, "2d"), (y, w), and4);  
  Or  ( SD(sd, "2d"), (and3, and4), X);
  
  And ( SD(sd, "2d"), (notw, x), and5);  
  Or  ( SD(sd, "2d"), (and5, z), Y);

  And ( SD(sd, "2d"), (notx, noty), and6);  
  Or  ( SD(sd, "2d"), (and6, w), Z);   
}

