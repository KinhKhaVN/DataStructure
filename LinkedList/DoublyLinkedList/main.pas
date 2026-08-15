PROGRAM DoublyLinkedList;

USES crt;

TYPE
  pNode = ^Node;
  Node = record
    value: integer;
    next: pNode;
    prev: pNode;
  end;

PROCEDURE
  Init(VAR head: pNode);
  BEGIN
    new(head);
    head := nil;
  END;

VAR
  head: pNode;

FUNCTION
  isEmpty(VAR head: pNode): boolean;
  BEGIN
    exit(head = nil);
  END;

PROCEDURE
  Print(VAR head: pNode);
  VAR
    tmpNode: pNode;
  BEGIN
    tmpNode := head;

    while tmpNode <> nil do
      BEGIN
        Write(tmpNode^.value, ' ');
        tmpNode := tmpNode^.next;
      END;

    Writeln;
  END;

PROCEDURE
  Add(VAR head: pNode; val: integer);
  VAR
    newNode, tmpNode: pNode;
  BEGIN
    new(newNode);
    newNode^.value := val;

    if isEmpty(head) then
      BEGIN
        head := newNode;
        exit;
      END;

    tmpNode := head;
    while tmpNode^.next <> nil do tmpNode := tmpNode^.next;

    tmpNode^.next := newNode;
    newNode^.prev := tmpNode;
  END;

BEGIN
  CLRSCR;

  Init(head);

  Add(head, 1);
  Add(head, 2);
 
  Print(head);
END.
