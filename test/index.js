const puppeteer = require('puppeteer');

puppeteer.launch({
	/**
	 * if you want to see console log in browser javascript, enable options.
	 * devtools: true,
 	*/
}).then(async browser => {
	const page = await browser.newPage();
	await page.addScriptTag({
		path: '../examples/build/libhtml5_example.js',
	});

	await page.on('console', async msg => {
		console.log(msg.text());
	});

	await page.evaluate(() => {
		Module.executeTest();
        return Promise.resolve();
	}).catch(e => {
	  	console.error(e);
	  	return Promise.resolve(e);
	});

	await browser.close();
});
