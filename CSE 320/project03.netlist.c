
/******************************************************************************
  Project #3 Jack Baldwin, A56528117
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;

  Signal Strobe (1);
  Signal ResetA (1);
  Signal ResetB (1);

  Counter ((SD("2c-3c"), "4 bit counter"), (ResetB, Strobe), (w,x,y,z));
  circuits( SD("1d-4d"), w, x, y, z, Present, a, b, c, d, e, f, g);


  Pulser ((SD("2a"), "r: Reset counter"), ResetA, 'r', 10001);
  Pulser ((SD("3a"), "s: Strobe counter"), Strobe, 's', 10000);

  Not (SD("2b"), ResetA, ResetB);

  Probe ((SD("1i"), "Present"), Present);
  Probe ((SD("3f-3i"), "a"), a);
  Probe ((SD("3i-6i"), "b"), b);
  Probe ((SD("6i-9i"), "c"), c);
  Probe ((SD("9f-9i"), "d"), d);
  Probe ((SD("6f-9f"), "e"), e);
  Probe ((SD("3f-6f"), "f"), f);
  Probe ((SD("6f-6i"), "g"), g);
  
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  Signal notw, notx, noty, notz;
  Signal and1, and2, and3, and4, and5, and6, and7, and8, and9;
  
  Not ( SD(sd, "2c"), w, notw );
  Not ( SD(sd, "2c"), x, notx );
  Not ( SD(sd, "2c"), y, noty );
  Not ( SD(sd, "2c"), z, notz );

  //Present
  And( SD(sd, "2c"), (notw, noty, z), and1);
  And( SD(sd, "2c"), (notw, y, notz), and2);
  And( SD(sd, "2c"), (notw, x, y), and3);
  And( SD(sd, "2c"), (w, notx, notz), and4);
  Or ( SD(sd, "2c"), (and1, and2, and3, and4), Present);

  //a
  Or ( SD(sd, "2c"), (x, notz), a);

  //b
  And( SD(sd, "2c"), (y, z), and5);
  Or ( SD(sd, "2c"), (notx, and5), b);
  
  //c
  Or ( SD(sd, "2c"), (w, noty, x), c);

  //d
  And( SD(sd, "2c"), (x, noty), and6); 
  And( SD(sd, "2c"), (w, noty), and7); 
  And( SD(sd, "2c"), (notw, notz), and8);
  Or ( SD(sd, "2c"), (and6, and7, and8), d);

  //e
  And( SD(sd, "2c"), (notz, notz), e);

  //f 
  And( SD(sd, "2c"), (x, notz), and9);
  Or ( SD(sd, "2c"), (w, and6, and9), f); //using and6 from d implementation

  //g
  Or ( SD(sd, "2c"), (notz, and6), g); //using and6 from d implementation

}

