/**
 * \file   Product.h
 * \author Adrian Stachlewski
 * \date   13-12-2015
 * \brief  Klasa przechowująca informacje o produkcie
 */

#ifndef PSZT_PRODUCT_H
#define PSZT_PRODUCT_H

#include <string>

/**
 * \brief Klasa przechowująca informacje o produkcie znajdującym się w magazynie.
 * Kazdy produkt opisany jest przez 3 parametry: nazwę, częstotliwość pobierania w ciągu dnia oraz czas załadunku,
 * gdy produkt znajduje sie na pierwszej półce.
 */
class Product {
public:
     /**
     * Konstruktor klasy Product, który wymaga podania wszystkich parametrów produktu.
     * \param name Nazwa produktu
     * \param frequency Częstotliwość pobierania produktu
     * \param loadingTime Czas załadunku produktu, gdy znajduje się na pierwszej półce
     */
    Product(const std::string &name, int frequency, double loadingTime) : name(name), frequency(frequency),
                                                                           loadingTime(loadingTime) { }

    const std::string& getName() const;
    int getFrequency() const;
    double getLoadingTime() const;

private:
    std::string name;           /**< Nazwa produktu */
    int frequency;              /**< Częstotliwość pobierania produktu */
    double loadingTime;        /**< Czas załadunku produktu, gdy znajduje się na pierwszej półce */
};


#endif //PSZT_PRODUCT_H
