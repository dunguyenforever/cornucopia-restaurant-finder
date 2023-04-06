(function(global, _) {
  
  var Dataset = global.Miso.Dataset;
  
  /**
   * This is a generic collection of dataset-building utilities that are used
   * by Miso.Dataset and Miso.DataView.
   *
   * @namespace Builder
   * @memberof Miso.Dataset
   */
  Dataset.Builder =
    /** @lends Miso.Dataset.Builder */
    {

    /**
     * Detects the type of a column based on some input data.
     *
     * @param {Miso.Dataset.Column} column The Column object
     * @param {Array} data Array of data to be scanned for type detection
     *
     * @returns {Miso.Dataset.Column} input column but typed.
     */
    detectColumnType : function(column, data) {

      // compute the type by assembling a sample of computed types
      // and then squashing it to create a unique subset.
      var type = _.inject(data.slice(0, 5), function(memo, value) {

        var t = Dataset.typeOf(value);

        if (value !== "" && memo.indexOf(t) === -1 && !_.isNull(value)) {
          memo.push(t);
        }
        return memo;
      }, []);

      // if we only have one type in our sample, save it as the type
      if (type.length === 1) {
        column.type = type[0];
      } else {
        //empty column or mixed type
        column.type = 'mixed';
      }

      return column;
    },

    /**
     * Detects the types of all columns in a dataset.
     *
     * @param {Miso.Dataset} dataset the dataset to test the columns of
     * @param {Array} parsedData the data to check the type of
     */
    detectColumnTypes : function(dataset, parsedData) {

      _.each(parsedData, function(data, columnName) {
        
        var column = dataset.column( columnName );
        
        // check if the column already has a type defined
        if ( column.type ) { 
          column.force = true;
          return; 
        } else {
          Dataset.Builder.detectColumnType(column, data);
        }

      }, this);
    },

    cacheRows : function(dataset) {

      Dataset.Builder.clearRowCache(dataset);

      // cache the row id positions in both directions.
      // iterate over the _id column and grab the row ids
      _.each(dataset._columns[dataset._columnPositionByName[dataset.idAttribute]].data, function(id, index) {
        dataset._rowPositionById[id] = index;
        dataset._rowIdByPosition.push(id);
      }, dataset);  

      // cache the total number of rows. There should be same 
      // number in each column's data
      var rowLengths = _.uniq( _.map(dataset._columns, function(column) { 
        return column.data.length;
      }));

      if (rowLengths.length > 1) {
        throw new Error("Row lengths need to be the same. Empty values should be set to null." + 
          _.map(dataset._columns, function(c) { return c.data + "|||" ; }));
      }
    },

    /**
     * Clears the row cache objects of a dataset
     *
     * @param {Miso.Dataset} dataset
     */
    clearRowCache : function(dataset) {
      dataset._rowPositionById = {};
      dataset._rowIdByPosition = [];
    },

    /**
     * Caches the column positions by name
     *
     * @param {Miso.Dataset} dataset
     */
    cacheColumns : function(dataset) {
      dataset._columnPositionByName = {};
      _.each(dataset._columns, function(column, i) {
        dataset._columnPositionByName[column.name] = i;
      });
    }
  };

  // fix lack of IE indexOf. Again.
  if (!Array.prototype.indexOf) { 
    Array.prototype.indexOf = function(obj, start) {
     for (var i = (start || 0), j = this.length; i < j; i++) {
         if (this[i] === obj) { return i; }
     }
     return -1;
    };
  }

}(this, _));
