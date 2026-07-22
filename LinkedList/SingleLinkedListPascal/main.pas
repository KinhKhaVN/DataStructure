PROGRAM LinkList;

USES crt;

TYPE
  pNode = ^Node;
  Node = record
    value: integer;
    next: pNode;
  END;

VAR
  head: pNode;
  i: integer;
  n: integer = 10;

PROCEDURE
  Init;
  BEGIN
    head := nil;
  END;

PROCEDURE
  Print;
  VAR
    tmpNode: pNode;
  BEGIN
    new(tmpNode);
    tmpNode := head;

    repeat
      Write(tmpNode^.value, ' ');
      tmpNode := tmpNode^.next;
    until tmpNode = nil;
    Writeln;
  END;

PROCEDURE
  Add(val: integer);
  VAR
    newNode: pNode;
    tmpNode: pNode;
  BEGIN
    new(newNode);
    newNode^.value := val;
    newNode^.next := nil;

    if head = nil then
      BEGIN
        head := newNode;
        exit;
      END;

    tmpNode := head;

    while tmpNode^.next <> nil do
      tmpNode := tmpNode^.next;

    tmpNode^.next := newNode;

  END;

PROCEDURE
  InsertAfter(target, val: integer);
  VAR
    tmpNode: pNode;
    newNode: pNode;
  BEGIN
    tmpNode := head;

    while (tmpNode <> nil) AND 
          (tmpNode^.value <> target)
           do 
          tmpNode := tmpNode^.next;

    if tmpNode = nil then
      BEGIN
        Add(val);
        exit;
      END;

    new(newNode);
    newNode^.value := val;
    newNode^.next := tmpNode^.next;
    tmpNode^.next := newNode;
    
  END;

BEGIN
  CLRSCR;


  Init;

  Add(1);
  Add(3);

  InsertAfter(1, 2);
  InsertAfter(4, 10);
  InsertAfter(5, 20);
  InsertAfter(10, 15);

  Print;
END.
