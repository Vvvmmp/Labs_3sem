using System;

namespace lab7
{
    public static class StatisticOperation
    {
        public static int differenceBetweenMaxAndMin(List list)
        {
            Node node = list.head;
            int max = int.MinValue;
            int min = int.MaxValue;

            while (node != null)
            {
                if (node.Data < min)
                    min = node.Data;
                if (node.Data > max)
                    max = node.Data;
                node = node.Next;
            }

            return max - min;
        }

        public static int CountElements(List list)
        {
            Node currentNode = list.head;
            int count = 0;

            while (currentNode != null)
            {
                count++;
                currentNode = currentNode.Next;
            }

            return count;
        }
    }
}