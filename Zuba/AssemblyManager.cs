using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Zuba
{
    internal static class AssemblyManager
    {
        internal static Assembly[] GetAssemblies()
        {
            string[] dlls = File.ReadAllLines(".dllsheet");
            List<Assembly> assemblies = new List<Assembly>();
            string loc = Assembly.GetExecutingAssembly().Location;
            loc = Path.GetDirectoryName(loc);
            foreach (string dll in dlls)
            {
                string path = loc + '\\' + dll;
                assemblies.Add(Assembly.LoadFile(loc + '\\' + dll));
            }
            return assemblies.ToArray();
        }
    }
}
