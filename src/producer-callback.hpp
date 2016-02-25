/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014 Regents of the University of California.
 *
 * @author Lijing Wang wanglj11@mails.tsinghua.edu.cn 
 */

#ifndef PRODUCER_CALLBACK_HPP
#define PRODUCER_CALLBACK_HPP
#include <Consumer-Producer-API/producer-context.hpp>
#include <Consumer-Producer-API/application-nack.hpp>
#include <boost/asio.hpp>

namespace ndn {
// Additional nested namespace could be used to prevent/limit name contentions
  class ProducerCallback
  {
  public:
    ProducerCallback();
    
    void
    setProducer(Producer* p);
    
    void
    setSampleNumber(size_t* n);

    void
    processConstData(Producer& pro, const Data& data);
    
    void
    processInterest(Producer& pro, const Interest& interest);
    
    void
    processOutgoingData(Producer& pro, const Data& data)
    {
      count ++;
      std::cout << "Callback total number: " << std::dec << count << std::endl; 
      std::cout << "Callback OutgoingData " << data.getName() << std::endl;
      std::cout << "Callback Payload Size " <<data.getContent().size() << std::endl; 
      std::cout << "Callback WholeData Size " <<data.wireEncode().size() << std::endl; 
      std::cout << "--- Segment " << count  << " Over--- " << std::endl; 
      //Send data
//      boost::system::error_code ec;
//      socket->write_some(boost::asio::buffer(data.wireEncode().wire(), data.wireEncode().size()), ec);
//      std::cout << "OutgoingData " << data.getName() << std::endl;
//      std::cout << data.getFinalBlockId() << std::endl;
    }

    void
    processOutgoingList(Producer& pro, const Data& data)
    {
      std::cout << "OutgoingList " << data.getName() << std::endl;
//      std::cout << data.getFinalBlockId() << std::endl;
    }

    void
    processIncomingInterest(Producer& pro, const Interest& interest);
    
    bool
    verifyInterest(Interest& interest);
    
    void
    processConstInterest(Producer& pro, const Interest& interest);

    void
    generateList(Producer& pro, const Interest& interest);
    
    std::string
    getFilename();
  
    std::string filepath;
    std::string prefix;
    int count;
//    boost::asio::io_service iosev;
//    boost::asio::ip::tcp::socket *socket;
    

  private:
    Producer* m_producer;
    size_t* m_curnum;
  };
  
} // namespace ndn
#endif
