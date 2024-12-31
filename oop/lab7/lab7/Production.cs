namespace lab7
{
    public class Production
    {
        public int ID;
        public string Name;

        public Production(int id, string name)
        {
            ID = id;
            Name = name;
        }

        public Production Create(int id, string name)
        {
            return new Production(id, name);
        }
    }
}