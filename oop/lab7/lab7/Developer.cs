namespace lab7
{
    public class Developer
    {
        public int ID;
        public string Name;
        public string FIO;

        public Developer(int id, string name, string fio)
        {
            ID = id;
            Name = name;
            FIO = fio;
        }

        public Developer Create(int id, string name, string fio)
        {
            return new Developer(id, name, fio);
        }
    }
}