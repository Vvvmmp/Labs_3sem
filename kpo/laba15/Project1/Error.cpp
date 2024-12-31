#include "stdafx.h"
#include "Error.h"
namespace Error {
	ERROr errors[ERROR_MAX_ENTRY]{ // òàáëèöà îøèáîê
		ERROR_ENTRY(0, "Íåäîïóñòèìûé êîä îøèáêè"),
		ERROR_ENTRY(1, "Ñèñòåìíûé ñáîé"),
		ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3),ERROR_ENTRY_NODEF(4),ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7),ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10),ERROR_ENTRY_NODEF10(20),ERROR_ENTRY_NODEF10(30),ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY_NODEF10(50),ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),
		ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Ïàğàìåòğ -in äîëæåí áûòü çàäàí"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102),ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "Ïğåâûøåíà äëèíà âõîäíîãî ïàğàìåòğà"),
		ERROR_ENTRY_NODEF(105),ERROR_ENTRY_NODEF(106),ERROR_ENTRY_NODEF(107),ERROR_ENTRY_NODEF(108),
		ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "Îøèáêà îòêğûòèÿ ôàéëà ñ èñõîäíûì êîäîì (-in)"),
		ERROR_ENTRY(111, "Íåäîïóñòèìûé ñèìâîë â èñõîäíîì ôàéëå (-in)"),
		ERROR_ENTRY(112, "Îøèáêà ïğè ñîçäàíèè ôàéëà ïğîòîêîëà(-log)"),
		ERROR_ENTRY_NODEF(113),ERROR_ENTRY_NODEF(114),ERROR_ENTRY_NODEF(115),ERROR_ENTRY_NODEF(116),
		ERROR_ENTRY_NODEF(117),ERROR_ENTRY_NODEF(118),ERROR_ENTRY_NODEF(119),ERROR_ENTRY_NODEF(120),
		ERROR_ENTRY_NODEF(130),ERROR_ENTRY_NODEF(140),ERROR_ENTRY_NODEF(150),ERROR_ENTRY_NODEF(160),
		ERROR_ENTRY_NODEF(170),ERROR_ENTRY_NODEF(180),ERROR_ENTRY_NODEF(190),ERROR_ENTRY_NODEF(200),
		ERROR_ENTRY_NODEF(300),ERROR_ENTRY_NODEF(400),ERROR_ENTRY_NODEF(500),ERROR_ENTRY_NODEF(600),
		ERROR_ENTRY_NODEF(700),ERROR_ENTRY_NODEF(800),ERROR_ENTRY_NODEF(900),
	};
	ERROr geterror(int id) { // ïîëó÷åíèå îøèáêè
		if (id > 0 && id < ERROR_MAX_ENTRY) { // ïğîâåğêà íà äîïóñòèìûé äèàïàçîí
			return errors[id]; // ïîëó÷àåì íóæíóş îøèáêó èç òàáëèöû
		}
		return errors[0]; // èíà÷å ïîëó÷àåì, ÷òî òàêàÿ îøèáêà íåäîïóñòèìà
	}
	ERROr geterrorin(int id, int line = -1, int col = -1) { // ïîëó÷àåì èíôîğìàöèş î ğàñïîëîæåíèè îøèáêè
		if (id > 0 && id < ERROR_MAX_ENTRY) { // åñëè îøèáêà äîïóñòèìà
			errors[id].inext.line = line; // çàïèñûâàåì ñòğîêó, íà êîòîğîé îíà íàõîäèòñÿ
			errors[id].inext.col = col; // çàïèñûâàåì ïîçèöèş, íà êîòîğîé îíà íàõîäèòñÿ
			return errors[id]; // âîçâğàùàåì îøèáêó
		}
		return errors[0]; // èíà÷å ïîëó÷àåì, ÷òî òàêàÿ îøèáêà íåäîïóñòèìà
	}
};