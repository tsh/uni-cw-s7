using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace TKPZ_kurs_1.Models
{
    public class AuctionsDataContext: DbContext
    {
        public DbSet<Auction> Auctions { get; set; }

        static AuctionsDataContext()
        {
            Database.SetInitializer(new DropCreateDatabaseIfModelChanges<AuctionsDataContext>());
        }
    }
}