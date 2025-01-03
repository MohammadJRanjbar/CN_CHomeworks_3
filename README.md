# CN_CA3


# **پروژه شبیه‌سازی شبکه**

---

## **شرح پروژه**
این پروژه با هدف شبیه‌سازی یک شبکه ساده توسعه داده شده است. در این شبیه‌سازی، مولفه‌هایی نظیر روترها، سیستم‌های مستقل (AS)، کاربران، بسته‌های داده، و رویدادهای چرخه‌ای به‌صورت برنامه‌ریزی‌شده پیاده‌سازی می‌شوند. در پایان این شبیه‌سازی، شبکه‌ای کامل ایجاد شده است که روترهای آن در ابتدا خاموش هستند.

---

## **مراحل انجام‌شده**

### **۱. پیاده‌سازی `EventsCoordinator`**
- این کلاس مسئول مدیریت چرخه‌های زمانی در شبیه‌سازی است.
- سیگنالی به نام `cycleTriggered` در هر چرخه فعال می‌شود که سایر اجزا (مانند تولیدکننده داده) را هماهنگ می‌کند.
- این کلاس به‌صورت Singleton پیاده‌سازی شده است تا از ایجاد چندین نمونه جلوگیری شود.

### **۲. پیاده‌سازی `MACAddress`**
- این کلاس نماینده آدرس‌های MAC در شبکه است.
- آدرس‌ها در قالب `XX:XX:XX:XX:XX:XX` ذخیره و مدیریت می‌شوند.
- قابلیت تولید آدرس‌های تصادفی و یکتا فراهم شده است.

### **۳. پیاده‌سازی `MACAddressGenerator`**
- این کلاس برای تولید آدرس‌های MAC یکتا به کار می‌رود.
- از تکرار آدرس‌ها جلوگیری می‌کند.

### **۴. پیاده‌سازی `Packet`**
- این کلاس نماینده یک بسته داده در شبکه است.
- هر بسته شامل اطلاعات زیر است:
  - **ID:** شناسه یکتای بسته.
  - **TTL:** زمان زندگی بسته.
  - **Headers:** هدرهای لایه داده و لایه TCP.
  - **Payload:** محتوای داده بسته.

### **۵. پیاده‌سازی `DataLinkHeader` و `TCPHeader`**
- `DataLinkHeader` شامل آدرس MAC مبدا و مقصد است.
- `TCPHeader` شامل اطلاعات پورت مبدا و مقصد است.

### **۶. پیاده‌سازی `DataGenerator`**
- این کلاس مسئول تولید بسته‌های داده در هر چرخه شبیه‌سازی است.
- بسته‌های داده بر اساس توزیع‌های آماری (Poisson یا Pareto) تولید می‌شوند.
- به هر بسته داده، هدرهای مناسب و محتوا (Payload) اختصاص داده می‌شود.
- از آدرس‌های MAC یکتا برای مبدا و مقصد بسته‌ها استفاده می‌شود.

---

## **ویژگی‌های فعلی**
- تولید بسته‌های داده با مشخصاتی شامل شناسه یکتا، TTL، هدرها و محتوا.
- تولید آدرس‌های MAC تصادفی و یکتا.
- شبیه‌سازی چرخه‌های زمانی با استفاده از کلاس `EventsCoordinator`.
- استفاده از توزیع‌های آماری برای تولید تعداد بسته‌ها در هر چرخه.

---

## **خروجی‌های تست**
- بسته‌ها با مشخصات کامل (ID، TTL، هدرها و محتوا) تولید شده‌اند.
- آدرس‌های MAC یکتا و بدون تکرار برای بسته‌ها اختصاص داده شده است.
- تعداد بسته‌های تولیدشده در هر چرخه بر اساس توزیع انتخاب‌شده محاسبه شده و در کنسول نمایش داده می‌شود.

---
