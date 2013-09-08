#include "serialization/NamedSerialize.h"
#include "storages/inmemstorage.h"

namespace demo
{
  struct some_subdata
  {		

    std::string str1;
    std::list<boost::uint64_t> array_of_id;

    BEGIN_NAMED_SERIALIZE_MAP()
      SERIALIZE_STL_ANSI_STRING(str1)
      SERIALIZE_STL_CONTAINER_POD(array_of_id)
    END_NAMED_SERIALIZE_MAP()
  };


  /************************************************************************/
  /*                                                                      */
  /************************************************************************/
	struct COMMAND_EXAMPLE_1
	{
		const static int ID = 1000;

		struct request
		{		

      std::string example_string_data;
      boost::uint64_t example_id_data;
      some_subdata sub;

      BEGIN_NAMED_SERIALIZE_MAP()
				SERIALIZE_STL_ANSI_STRING(example_string_data)
				SERIALIZE_POD(example_id_data)
        SERIALIZE_T(sub)
			END_NAMED_SERIALIZE_MAP()
		};


		struct response
		{
			bool 	 m_success; 
      std::list<some_subdata> subs;

			BEGIN_NAMED_SERIALIZE_MAP()
				SERIALIZE_POD(m_success)
				SERIALIZE_STL_CONTAINER_T(subs)
			END_NAMED_SERIALIZE_MAP()
		};
	};



	struct COMMAND_EXAMPLE_2
	{
		const static int ID = 1001;

    struct request
    {		
      std::string example_string_data2;

      BEGIN_NAMED_SERIALIZE_MAP()
        SERIALIZE_STL_ANSI_STRING(example_string_data2)
      END_NAMED_SERIALIZE_MAP()
    };

    struct response
    {
      bool 	 m_success; 

      BEGIN_NAMED_SERIALIZE_MAP()
        SERIALIZE_POD(m_success)
      END_NAMED_SERIALIZE_MAP()
    };
	};
}

//here cold be different storage types - gzipped, encrypted etc
namespace epee
{
  namespace StorageNamed
  {
    typedef CInMemStorage DefaultStorageType;
  }
}
