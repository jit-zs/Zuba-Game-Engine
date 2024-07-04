using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zuba
{
    [System.AttributeUsage(AttributeTargets.All, Inherited = false, AllowMultiple = true)]
    sealed class ComponentMenuAttribute : Attribute
    {
        readonly string positionalString;

        // This is a positional argument
        public ComponentMenuAttribute(string positionalString)
        {
            this.positionalString = positionalString;

            // TODO: Implement code here

            throw new NotImplementedException();
        }

        public string PositionalString
        {
            get { return positionalString; }
        }

        // This is a named argument
        public int NamedInt { get; set; }
    }
}
