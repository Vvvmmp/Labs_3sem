using System;

namespace lab7
{
    public class List
    {
        public Node head;

        public List()
        {
            head = null;
        }

        public void Append(int data)
        {
            Node newNode = new Node(data);
            if (head == null)
            {
                head = newNode;
                return;
            }

            Node lastNode = head;
            while (lastNode.Next != null)
            {
                lastNode = lastNode.Next;
            }
            lastNode.Next = newNode;
        }

        public void PrintList()
        {
            Node currentNode = head;
            while (currentNode != null)
            {
                Console.Write(currentNode.Data + " ");
                currentNode = currentNode.Next;
            }
            Console.WriteLine();
        }

        public static List operator !(List list)
        {
            List invertedList = new List();
            Node currentNode = list.head;

            while (currentNode != null)
            {
                Node newNode = new Node(currentNode.Data);
                newNode.Next = invertedList.head;
                invertedList.head = newNode;
                currentNode = currentNode.Next;
            }
            return invertedList;
        }

        public static List operator +(List list1, List list2)
        {
            List combinedList = new List();
            Node currentNode = list1.head;

            while (currentNode != null)
            {
                combinedList.Append(currentNode.Data);
                currentNode = currentNode.Next;
            }

            currentNode = list2.head;
            while (currentNode != null)
            {
                combinedList.Append(currentNode.Data);
                currentNode = currentNode.Next;
            }
            return combinedList;
        }

        public static bool operator ==(List left, List right)
        {
            Node nodeLeft = left.head;
            Node nodeRight = right.head;

            while (nodeLeft != null && nodeRight != null)
            {
                if (nodeLeft.Data != nodeRight.Data)
                    return false;

                nodeLeft = nodeLeft.Next;
                nodeRight = nodeRight.Next;
            }

            return nodeLeft == null && nodeRight == null;
        }

        public static bool operator !=(List left, List right)
        {
            return !(left == right);
        }

        public static List operator <(List left, List right)
        {
            Node currentNode = right.head;

            while (currentNode != null)
            {
                left.Append(currentNode.Data);
                currentNode = currentNode.Next;
            }
            return left;
        }

        public static List operator >(List left, List right)
        {
            Node currentNode = left.head;

            while (currentNode != null)
            {
                right.Append(currentNode.Data);
                currentNode = currentNode.Next;
            }
            return right;
        }
    }
}