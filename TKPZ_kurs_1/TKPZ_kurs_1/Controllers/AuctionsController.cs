using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace TKPZ_kurs_1.Controllers
{
    public class AuctionController : Controller
    {
        //
        // GET: /Auctions/

        public ActionResult Index()
        {
            return View();
        }

        public ActionResult TempDataDemo()
        {
            TempData["SuccessMessage"] = "The action succeeded!";

            return RedirectToAction("Index");
        }

        public ActionResult Auction()
        {
            var auction = new TKPZ_kurs_1.Models.Auction()
            {
                Title = "Example",
                Description = "This is an example",
                StartTime = DateTime.Now,
                EndTime = DateTime.Now.AddDays(7),
                StartPrice = 1.00m,
                CurrentPrice = null,
            };

            return View(auction);
        }

    }
}
