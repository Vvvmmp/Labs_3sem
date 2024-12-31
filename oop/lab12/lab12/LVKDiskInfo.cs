using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab12
{
    internal class LVKDiskInfo
    {
        private readonly LVKLog logger;
        public LVKDiskInfo(LVKLog log) 
        {
            logger = log;
        }

        public string GetFullInfo()
        {
            var info = new StringBuilder();
            DriveInfo[] drives = DriveInfo.GetDrives();

            foreach (DriveInfo drive in drives)
            {
                info.AppendLine($"Название: {drive.Name}");
                info.AppendLine($"Тип: {drive.DriveType}");
                if(drive.IsReady)
                {
                    info.AppendLine($"Объём диска: {drive.TotalSize}");
                    info.AppendLine($"Свободное пространство: {drive.TotalFreeSpace}");
                    info.AppendLine($"Метка диска: {drive.VolumeLabel}");
                    
                    logger.WriteLog("Информация о диске", $"Название: {drive.Name}, Объём: {drive.TotalSize}, Свободное: {drive.TotalFreeSpace}, Метка: {drive.VolumeLabel}");
                }
                else
                {
                    info.AppendLine("Диск не готов.");
                    logger.WriteLog("Информация о диске", $"Название: {drive.Name}, Статус: не готов");
                }
                Console.WriteLine();
            }
                return info.ToString();
            }

        }

    }

