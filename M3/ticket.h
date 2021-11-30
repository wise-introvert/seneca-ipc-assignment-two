#ifndef _TICKE_H_
#define  _TICKET_H_

struct Message {
  char authorAccountType;
  char authorAcountName[32];
  char message[155];
};

struct Ticket {
  int uniqueNumber;
  int customerAccountNumber;
  int ticketStatus; // 0 is closed , 1 is still open
  char subjectLine[32];
  int messageCounter;
  struct Message messages[20];
};

#endif
