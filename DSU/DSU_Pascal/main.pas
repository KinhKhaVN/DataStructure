PROGRAM DSU;

USES crt;

CONST
  capacity = 10;

TYPE
  aset = array[0..capacity - 1] of integer;


VAR
  p: aset;
  n: integer;

PROCEDURE
  Init;
  VAR
    i: integer;
  BEGIN
    n := 10;

    for i := 0 to n - 1 do
      BEGIN
        p[i] := i;
      END;
  END;

FUNCTION
  Find(VAR x: integer): integer;
  BEGIN
    if p[x] = x then exit(x);
    
    p[x] := Find(p[x]);

    exit(p[x]);
  END;

PROCEDURE
  Swap(VAR a, b: integer);
  VAR
    tmp: integer;
  BEGIN
    tmp := a;
    a := b;
    b := tmp;
  END;

PROCEDURE
  Union(x, y: integer);
  BEGIN
    x := Find(x);
    y := Find(y);
    
    if x = y then exit;

    if x < y then Swap(x, y);

    p[x] := y;
  END;

PROCEDURE
  Print(VAR A: aset; VAR n: integer);
  VAR
    i: integer;
  BEGIN
    for i := 0 to n - 1 do
      Write(i, ' ');
    Writeln;
    for i := 0 to n - 1 do
      Write(A[i], ' ');
    Writeln;
  END;

BEGIN
  CLRSCR;

  Init;

  Union(1, 2);
  Union(3, 4);
  {Union(1, 4);}
  Union(4, 9);

  Print(p, n);
END.
