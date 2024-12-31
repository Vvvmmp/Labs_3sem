namespace lab7
{
    public static class IntExtensions
    {
        public static int Sum(this List list)
        {
            int sum = 0;
            Node currentNode = list.head;

            while (currentNode != null)
            {
                sum += currentNode.Data;
                currentNode = currentNode.Next;
            }

            return sum;
        }

        public static List Truncate(this List list, int length)
        {
            List truncatedList = new List();
            Node currentNode = list.head;
            int count = 0;

            while (currentNode != null && count < length)
            {
                truncatedList.Append(currentNode.Data);
                currentNode = currentNode.Next;
                count++;
            }
            return truncatedList;
        }
    }
}