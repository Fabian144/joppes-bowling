## Rädda Joppes Bowling!

Joppes Bowling är i akut behov av ett nytt bokningssystem. Det nuvarande systemet består av en kaffefläckig anteckningsbok, tre lösa post-it-lappar och Joppes minne – vilket tyvärr inte är lika träffsäkert som hans bowlingklot.

Kalle vill därför att vi utvecklar ett program i C där personalen kan registrera kunder. Varje kund ska ha:

- ett unikt kund-id
- ett namn
- en adress
- antalet gånger kunden har bowlat

Bowlinghallen har flera banor. Varje bana har ett unikt bannummer och kan vara bokad under olika tidsintervall. En bokning ska innehålla:

- ett boknings-id
- kundens id
- banans nummer
- datum
- en tids-slot, exempelvis `09:00–10:00`
- antal spelare
- status, exempelvis aktiv eller avbokad

Systemet ska kontrollera att samma bana inte bokas av flera kunder vid samma tid. Två sällskap får alltså inte dela bana av misstag – det leder lätt till förvirring, flygande klot och mycket dåliga recensioner.

Personalen ska kunna:

1. Registrera en ny kund.
2. Visa alla registrerade kunder.
3. Söka efter en kund med hjälp av kund-id.
4. Uppdatera kundens namn, adress eller antal bowlingbesök.
5. Skapa en ny bokning.
6. Visa alla bokningar.
7. Visa bokningar för en viss kund.
8. Visa bokningar för en viss bana eller ett visst datum.
9. Avboka en bokning.
10. Kontrollera om en bana är ledig under en viss tids-slot.

När en genomförd bokning registreras ska kundens antal bowlingbesök kunna ökas. Kunder som har bowlat minst tio gånger får gärna markeras som stamkunder. De får inga automatiska rabatter ännu, men de kan åtminstone känna sig sedda.

Informationen om kunder och bokningar ska lagras i filer så att allt finns kvar när programmet avslutas. När programmet startar ska tidigare sparade uppgifter läsas in igen. Kalle vill absolut inte behöva skriva in alla kunder varje morgon – särskilt inte före den första koppen kaffe.

Programmet bör använda en eller flera `struct`-typer, exempelvis `Customer`, `Lane` och `Booking`. Det ska också ha en tydlig meny som fortsätter visas tills användaren väljer att avsluta programmet.

All inmatning bör kontrolleras så att programmet inte kraschar om någon råkar skriva `"gurka"` där ett bannummer förväntas. Systemet ska också visa begripliga felmeddelanden när exempelvis en kund inte finns eller en bana redan är bokad.

Målet är att skapa ett enkelt men fungerande bokningssystem som hjälper Joppe att hålla ordning på kunder, banor och bokningar. Om systemet fungerar kanske Joppe äntligen kan ägna sig åt bowlinghallen i stället för att leta efter borttappade post-it-lappar.