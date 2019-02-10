import scrapy

class MediaGalaxy(scrapy.Spider):
    name = "media"

    def start_requests(self):
        urls = [
                'https://mediagalaxy.ro/laptopuri/cpl/filtru/tip-procesor-1991/intel-core-i7/order/price/dir/asc/',
                ]
        for url in urls:
            yield scrapy.Request(url=url, callback=self.parse)


    def parse(self, response):
        page = response.url.split("/")[-2]
        filename = 'quotes-%s.html' % page
        with open(filename, 'wb') as f:
            f.write(response.body)
        self.log('Saved file %s' % filename)


