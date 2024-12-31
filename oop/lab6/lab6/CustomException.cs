using System;

namespace lab6
{
    internal class CustomException : Exception
    {
        public CustomException(string message) : base(message) { }

        public class EquipmentEqualsZero : CustomException
        {
            public EquipmentEqualsZero() : base("Оборудование не может быть пустым!") { }
        }

        public class PriceLessThanZero : CustomException
        {
            public PriceLessThanZero() : base("Цена не может быть отрицательной!") { }
        }

        public class MaterialsEqualsNull : CustomException
        {
            public MaterialsEqualsNull() : base("Материалы не могут быть null!") { }
        }
    }
}