PROGRAM QueueArray;

USES crt;

CONST
  capacity = 5;

VAR
  head, tail: integer;

  A: array[0..capacity - 1] of integer;

PROCEDURE
  Init;
  BEGIN
    head := 0;
    tail := 0;
  END;

FUNCTION
  isEmpty: boolean;
  BEGIN
    exit(tail = 0);
  END;

FUNCTION
  isFull: boolean;
  BEGIN
    exit(tail = capacity);
  END;

PROCEDURE
  Push(x: integer);
  BEGIN
    if isFull then
      BEGIN
        Writeln('Queue is full!');
        Writeln('Cannot push ', x);
        exit;
      END;

    A[tail] := x;
    inc(tail);
  END;

PROCEDURE
  Pop;
  BEGIN
    if isEmpty then
      BEGIN
        Writeln('Queue is empty!');
        Writeln('Cannot pop');
        exit;
      END;
    dec(tail);
  END;

PROCEDURE
  Print;
  VAR
    i: integer;
  BEGIN
    for i := head to tail - 1 do
      Write(A[i], ' ');
    Writeln;
  END;
BEGIN
  CLRSCR;

  Init;

  Push(1);
  Push(2);
  Push(2);
  Push(2);
  Push(2);
  Push(100);
  Push(200);

  Print;
END.
