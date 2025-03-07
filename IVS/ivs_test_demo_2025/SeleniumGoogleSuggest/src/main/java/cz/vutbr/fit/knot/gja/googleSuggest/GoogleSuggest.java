/*
 * Project: Examples for GJA course
 * Authors: Ing. Jan Kouřil
 *          Ing. Jaroslav Dytrych idytrych@fit.vutbr.cz
 * File: GoogleSuggest.java
 * Description: Example of Selenium driver usage
 */

/**
 * @file GoogleSuggest.java
 *
 * @brief Example of Selenium driver usage
 */

/**
 * @package cz.vutbr.fit.knot.gja.googleSuggest
 * 
 * @brief Example of Selenium driver usage
 */
package cz.vutbr.fit.knot.gja.googleSuggest;


import java.io.File;
import java.io.IOException;
import java.time.Duration;
import java.util.List;
import org.apache.commons.io.FileUtils;

import org.openqa.selenium.By;
import org.openqa.selenium.OutputType;
import org.openqa.selenium.TakesScreenshot;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
//import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

/**
 * Example of Selenium driver usage
 */
public class GoogleSuggest {
  
  /**
   * Main method - gets suggestions from Google
   * @param args Command line arguments
   * @throws java.io.IOException if saving of screenshot fails
   */
  public static void main(String[] args) throws IOException {
    
    // For Firefox
    //System.setProperty("webdriver.gecko.driver", "geckodriver");
    //WebDriver driver = new FirefoxDriver();  // initialise Firefox driver
    
    // For Google Chrome
    System.setProperty("webdriver.chrome.driver", "chromedriver");
    WebDriver driver = new ChromeDriver();
    
    
    driver.get("http://www.google.com");  // Open URL
    WebElement consentElement = driver.findElement(By.id("L2AGLb"));  // Find cookie consent button
    consentElement.click();
    WebElement element = driver.findElement(By.name("q"));  // Find search input
    element.sendKeys("Cheese!\n");  // Fill in searched word, send also a "\n"
    //element.submit();  // uncomment for Firefox

    // wait until the google page shows the result
    WebElement myDynamicElement = (new WebDriverWait(driver, Duration.ofSeconds(15))).until(ExpectedConditions.presenceOfElementLocated(By.id("result-stats")));

    // Search for links in headers
    List<WebElement> findElements = driver.findElements(By.xpath("//*[@id='rso']//a"));

    // Print out the links
    for (WebElement webElement : findElements) {
      System.out.println(webElement.getAttribute("href"));
    }
    
    File scrFile = ((TakesScreenshot)driver).getScreenshotAs(OutputType.FILE);
    FileUtils.copyFile(scrFile, new File("screenshot.png"));

    driver.quit();
  }
}